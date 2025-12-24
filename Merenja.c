#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Upotreba: %s <ime_fajla>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* ulaz = fopen(argv[1], "r");
    if (!ulaz) {
        printf("Greska pri otvaranju fajla!\n");
        return EXIT_FAILURE;
    }

    int broj;
    int ukupno = 0;
    int brojac = 0;

    // Prvi prolaz: prebroji brojeve i saberi ih
    while (fscanf(ulaz, "%d", &broj) == 1) {
        ukupno += broj;
        brojac++;
    }

    rewind(ulaz); // vrati pokazivač na početak fajla

    // Prosek
    int prosek = ukupno / brojac;

    printf("Ukupan broj clanova: %d\n", brojac);
    printf("Prosek: %d\n", prosek);
    printf("Brojevi veci od proseka: ");

    // Drugi prolaz: ispiši brojeve veće od proseka
    while (fscanf(ulaz, "%d", &broj) == 1) {
        if (broj > prosek)
            printf("%d ", broj);
    }
    printf("\n");

    fclose(ulaz);
    return 0;
}

