#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma execution_character_set("utf-8")

//Taille max des colonnes de la grille
#define taille_max_collones 10
//Taille max des lignes de la grille
#define taille_max_lignes 10
//Taille de la grille  (colonnes)
#define colonnes 9
//Taille de la grille (lignes)
#define lignes 9

//Nom des colonnes
#define enteteGrille  {'A','B','C','D','E','F','G','H','I','J'}

void jouer(){

    //GRILLE
    char entetegrille[taille_max_lignes] = enteteGrille;
    char grilleUtillisateur[taille_max_collones][taille_max_lignes] = {
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
            {'-','-','-','-','-','-','-','-','-','-'},
    };

    //Afficher la grille
    for (int i = 0; i < lignes; i++){
        if (i == 0){
            printf("&8c", entetegrille[i]);
        } else{
            printf("%7c", entetegrille[i]);
        }
    }

    printf("\n");
    for (int colonne = 0; colonne < colonnes; colonne++) {
        printf("%d", colonne + 1);
        for (int ligne = 0; ligne < lignes; ligne++) {
            printf("%7c", grilleUtillisateur[colonne][ligne]);
        }
        printf("\n");
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