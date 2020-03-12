#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma execution_character_set("utf-8")


void jouer(){
    printf("Game");
}

void aide(){
    FILE* fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("aide.txt", "r");

    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);
        }
        while (caractereActuel != EOF);
    
        fclose(fichier);
    }
    return 0;
}

void menu(){
    int choixmenu;

    printf("Bataille Navale\n\n");

    printf("1 - Jouer \n");
    printf("2 - Scores \n");
    printf("3 - S'authentifier \n");
    printf("4 - Aide \n");
    printf("5 - Quitter \n");
    scanf("%d", &choixmenu);


    switch(choixmenu){
        case 1: jouer();
            break;

        case 2:
            printf("Scores\n");
            break;

        case 3:
            printf("S'authentifier\n");
            break;

        case 4: aide();
            break;

        case 5:
            break;

        default:system("cls");
                menu();
                break;
    }
}

int main() {
    SetConsoleOutputCP(65001);

   //appeler fonction menu
   menu();


   printf("\n\n");
   system("pause");
    return 0;
}