#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Inkludér time.h for at generere tilfældige tal ved brug af tid

int main() {
    // Generer et tilfældigt tal ved brug af tid.
    srand(time(0));

    int choice; //Lav Int for ens eget valg
    int computerChoice; //Lav Int for computerens valg

    while (1) { //Lav menu
        printf("Vaelg en handling:\n");
        printf("1. Sten\n");
        printf("2. Saks\n");
        printf("3. Papir\n");
        printf("0. Afslut spillet\n");

        // Få brugerens valg
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Spillet afsluttet. Farvel!\n");
            break; // Gå ud af spillet
        } else if (choice < 1 || choice > 3) {
            printf("Ugyldigt valg. Proev igen.\n");
        } else { // Generer tilfældigt valg indenfor scope af 3 + 1)
            computerChoice = rand() % 3 + 1;

            // Display the choices made by the user and the computer
            printf("Dit valg: ");
            switch (choice) {
                case 1:
                    printf("Sten\n");
                    break;
                case 2:
                    printf("Saks\n");
                    break;
                case 3:
                    printf("Papir\n");
                    break;
            }
            printf("Computerens valg: ");
            switch (computerChoice) {
                case 1:
                    printf("Sten\n");
                    break;
                case 2:
                    printf("Saks\n");
                    break;
                case 3:
                    printf("Papir\n");
                    break;
            }

            // Bestem vinderen
            if (choice == computerChoice) {
                printf("Uafgjort!\n"); // && Betyder sammenligne
            } else if ((choice == 1 && computerChoice == 2) || (choice == 2 && computerChoice == 3) || (choice == 3 && computerChoice == 1)) {
                printf("Du vinder!\n");
            } else {
                printf("Computeren vinder!\n");
            }
        }
    }

    return 0;
}
