#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Inkludér time.h for at generere tilfældige tal ved brug af tid

    int choice; //Lav Int for ens eget valg
    int computerChoice; //Lav Int for computerens valg
    int computerPoint = 0;
    int spillerPoint = 0;
    int uafgjort = 0;

    void loadScore() {
        FILE * file = fopen("scores.txt", "r");
            if (file != NULL) {
                fscanf(file, "%d %d %d", & spillerPoint, & computerPoint, & uafgjort);
                fclose(file);
   }
}

    void saveScore() {
        FILE * file = fopen("scores.txt", "w");
            if (file != NULL) {
                fprintf(file, "%d %d %d", spillerPoint, computerPoint, uafgjort);
                fclose(file);
   }
}

int main() {
    // Generer et tilfældigt tal ved brug af tid.
    srand(time(0));
    loadScore();

    while (1) { //Lav menu
        printf("-----------------------\n");
        printf("Vaelg en handling:\n");
        printf("1. Sten\n");
        printf("2. Saks\n");
        printf("3. Papir\n");
        printf("9. Nulstil point\n");
        printf("0. Afslut spillet\n\n");
        printf("Spiller point: %d\n", spillerPoint);
        printf("Computer point: %d\n", computerPoint);
        printf("Uafgjort: %d\n\n", uafgjort);

        // Få brugerens valg
        scanf("%d", &choice);

        if (choice == 9) {
            computerPoint = 0;
            spillerPoint = 0;
            uafgjort = 0;
        printf("Point nulstilling succesfuld!");
        }

        if (choice == 0) {
            printf("Spillet afsluttes. Farvel!\n\n");
            saveScore();
                if (spillerPoint>computerPoint)
                {   printf("-----------------------\n");
                    printf("SPILLEREN VANDT!\n");
                    printf("-----------------------\n"); }
                else if (spillerPoint<computerPoint)
                {   printf("-----------------------\n");
                    printf("COMPUTEREN VANDT!\n");
                    printf("-----------------------\n"); }
                else
                {   printf("-----------------------\n");
                    printf("SPILLET ENDTE UAFGJORT!\n");
                    printf("-----------------------\n"); }
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
                printf("Uafgjort!\n\n"); // && Betyder sammenligne
                uafgjort++;
            } else if ((choice == 1 && computerChoice == 2) || (choice == 2 && computerChoice == 3) || (choice == 3 && computerChoice == 1)) {
                printf("Du vinder!\n\n");
                spillerPoint++;
            } else {
                printf("Computeren vinder!\n\n");
                computerPoint++;
            }
        }
    }

    return 0;
}
