/**
 * \project Bataille Navale
 * \author Volery Sven
 * \date 04.03.2020
 * \version 0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>

//Afficher les accents
#pragma execution_character_set("utf-8")

//Taille max des colonnes de la grille
#define taille_max_colonnes 10
//Taille max des lignes de la grille
#define taille_max_lignes 10
//Taille de la grille  (colonnes)
#define Colonnes 9
//Taille de la grille (lignes)
#define Lignes 9
//Nom des colonnes
#define Entete_Grille  {'A','B','C','D','E','F','G','H','I','J'}

//Variable si oui ou non on sort du programme
int quit = 0;

void jouer(){

    //Grille
    char entete_grille[taille_max_lignes]  = Entete_Grille;
    char grille_utillisateur[taille_max_colonnes][taille_max_lignes] = {
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


    //Affichage de la grille

    //Afficher entête des colonnes
    for (int t = 0; t < Lignes; t++){
        if(t == 0){
            printf("%8c", entete_grille[t]);
        }else{
            printf("%7c", entete_grille[t]);
        }
    }
    printf("\n");
    for (int colonne = 0; colonne < Colonnes; colonne++ ){
        printf("%d", colonne + 1);
        for (int ligne = 0; ligne < Lignes; ligne++){
            printf("%7c", grille_utillisateur[colonne][ligne] );
        }
        printf("\n");
    }
    system("pause");
}

void aide()
{
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
    int choix = 0;
    //Afficher les accents
    SetConsoleOutputCP(65001);

   //appeler fonction menu
    system("cls");
   menu(choix);


   printf("\n\n");

    if(quit == 0){
        return main();
    } else {
        return 0;
    }
}