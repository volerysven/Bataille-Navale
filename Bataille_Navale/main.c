#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

#pragma execution_character_set("utf-8")
//Grille
char grilledebase[10][10] = {
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
};


//Grille_Bateaux
int masquegrille[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 5, 5, 5, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 3, 3, 3, 0, 0, 0},
        {0, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};



int jouer() {
    bool jeu = true;
    int a = 0, z = 0, vertical, horizontal;

    printf("\n");
    while (jeu == true) {
        for (int z = -1; z < 10; ++z) {
            printf("%d\t", z + 1);
        }
        printf("\n");
        for (int a = 0; a < 10; a++) {
            printf("%d\t", a + 1);
            for (int z = 0; z < 10; z++) {

                printf("%c\t", grilledebase[a][z]);
            }
            printf("\n");
        }

//Info toucher ou louper
        printf("\nT = Toucher\n");
        printf("L = Louper\n");

//Demande des tires verticales et horizontal
        printf("\nTir horizontal : ");
        scanf("%d", &horizontal);
        printf("Tir vertical : ");
        scanf("%d", &vertical);

        horizontal = horizontal - 1;
        vertical = vertical - 1;



//Si la case choisie et entre 1 et 6 touché donc afficher 'T' sinon afficher 'L'
        if (masquegrille[horizontal][vertical] == 1 ||
            masquegrille[horizontal][vertical] == 2 ||
            masquegrille[horizontal][vertical] == 3 ||
            masquegrille[horizontal][vertical] == 4 ||
            masquegrille[horizontal][vertical] == 5 ||
            masquegrille[horizontal][vertical] == 6) {
            grilledebase[horizontal][vertical] = 'T';
        } else {
            grilledebase[horizontal][vertical] = 'L';
        }
        system("cls");
    }
}

//Va chercher le fichier aide pour qu'il puisse s'afficher
void aide() {
    FILE *fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("aide.txt", "r");

    if (fichier != NULL) {
        do {
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);
        } while (caractereActuel != EOF);
        system("pause");
        fclose(fichier);
    }

}

void menu() {
    int choixmenu;

    printf("Bataille Navale\n\n");

    printf("1 - Jouer \n");
    printf("2 - Scores \n");
    printf("3 - S'authentifier \n");
    printf("4 - Aide \n");
    printf("5 - Quitter \n\n");
    scanf("%d", &choixmenu);


    switch (choixmenu) {
        case 1:
            jouer();
            break;

        case 2:
            printf("Scores\n");
            break;

        case 3:
            printf("S'authentifier\n");
            break;

        case 4:
            aide();
            break;

        case 5:
            break;

        default:
            system("cls");
            menu();
            break;
    }
}

int main() {
    SetConsoleOutputCP(65001);

    //appeler fonction menu
    menu();

    return 0;
}

