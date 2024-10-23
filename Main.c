#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>



void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void initialisationDuPlat(char plateau[19][19]);
void remplissage_plateau( char plateau[19][19]);
void affichage_plateau( char plateau[19][19]);

unsigned char Jeton();

void Depart1(char plateau[19][19],int j, int jj, unsigned char J1, unsigned char J2);
void Depart2(char plateau[19][19], int j, int i, int jj, int ii, unsigned char J1, unsigned char J2, unsigned char J3, unsigned char J4);
char Ordre2(char nom1[20], char nom2[20], char nom3[20], char nom4[20]);



void CASE_Libre(char plateau[19][19], int J);
void Deplacer1B( char plateau [19][19], int i1, int j1, int i2, int j2, unsigned char J1, unsigned char J2,int h);
void Deplacer2( char plateau[19][19], int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4, unsigned char J1,unsigned char J2, unsigned char J3, unsigned char J4,int g);

int Gagnant1(int i1);
int Gagnant2(int i2);
int Gagnant2b(int j2);
int Gagnant3(int i3);
int Gagnant4(int j4);

void Barriere(char plateau[19][19], int i1, int j1, int i2, int j2);
void Barrierepose(char plateau[19][19], int tabi[20], int tabj[20]);

void sauvegarder_score(char nom1[20], char nom2[20], int s1, int s2);
void sauvegarder_score2(char nom1[20], char nom2[20], char nom3[20], char nom4[20], int s1, int s2, int s3, int s4);
void score();

void sauvegarder_partie1(char nom1[20], char nom2[20], unsigned char J1, unsigned char J2, int i, int j, int ii, int jj );
void partie();

void affichage_plateauB( char plateau[19][19], int i, int j, int ii, int jj);
void initialisationDuPlatB(char plateau[19][19], int i1, int j1, int ii, int jj);

int Colonne(char CC);
int Ligne(int CL);
int ColonneB(char CC);
int LigneB(unsigned char CL);


int ColonneE(char CC);
int LigneE(char CC);

int Menu();
int MenuAction();
int menudeplacer();
int Aide_Menu();






            //MAIN.

int main()
{

            //DECLARATION DES VARIABLES.
    int menu, menuaction, menud;
    int alea1, alea2;
    int mur1=10, mur2=10, mur1b=5, mur2b=5, mur3=5, mur4=5;
    srand(time(NULL));
    int joueur;
    char nom1[20], nom2[20], nom3[20], nom4[20];
    unsigned char J1, J2, J3, J4;
    char A[20], B[20], C[20], D[20];
    int LC;
    unsigned char c1,c2,l2,CC;
    int oui;
    char plateau[19][19];
    int i1,j1,i2,j2,i3,j3,i4,j4;
    int ib1,jb1,ib2,jb2;
    int mod=0;
    int score1=0, score2=0, score3=0, score4=0;
    int G1=0,G2=0,G3=0,G4=0;
    int j, jj, i, ii;
    char D1,D2,D3;
    int d2,D4;
    unsigned char ll;
    int h,g;

    FILE*fp;
    fp=fopen("SCORE.txt","r");



        //AFFICHE LE MENU PRINCIPAL TANT QUE L'ON NE QUITTE PAS LE JEU.

    do {
    menu= Menu();       //Affichage du menu.
    system("cls");


    switch(menu)
    {

            //COMMENCER UNE NOUVELLE PARTIE.

    case 1:

        // CHOIX DU NOMBRE DE JOUEURS.
        do
        {
    printf("\n\n\n              ==== Veuillez saisir le nombre de joueurs: ====\n");
    printf("                           2 joueurs ou 4 joueurs\n");
    scanf("%d",&joueur);
        }while((joueur!=2)&&(joueur!=4));


        // COMMENCER UNE PARTIE AVEC 2 JOUEURS
    if (joueur==2)
    {

        // Saisie des noms des 2 joueurs.
        printf("Veuillez saisir le pseudo des deux joueurs:\n");
        printf("            Pseudo 1:\n");
        scanf("%s",&nom1);
        printf("            Pseudo 2:\n");
        scanf("%s",&nom2);
        system("cls");


        // Ordre de passage des joueurs choisi aléatoirement.
        alea1=rand()%2;
        if(alea1==1){
            strcpy(A,nom1);
            strcpy(B,nom2);
        }
        else{
            strcpy(A,nom2);
            strcpy(B,nom1);
        }

        // Tirage des jetons de façon aléatoire.
        J1=Jeton();
        do{
            J2=Jeton();
        }while(J2==J1);

        // Affichage du plateau afin que les joueurs choisissent leurs positions de depart.

        initialisationDuPlat(plateau);
        affichage_plateau(plateau);
        printf("Joueur 1 veuillez choisir une case de depart sur la ligne 1:\n");
        scanf("%s",&D1);
        printf("Joueur 2 veuillez choisir une case de depart sur la ligne 9:\n");
        scanf("%s",&D2);


        // Convertie les coordonnées saisit par le joueur à l'aide du sous programme Colonne().

        j=Colonne(D1);
        jj=Colonne(D2);

        // Affiche le plateau de départ.

        system("cls");
        gotoligcol(3,0);
        Depart1(plateau, j, jj, J1, J2);
        i2=17;
        j2=jj;


        // Permet de faire jouer les 2 joueurs jusqu'a ce que la partie soit terminée. (un gagant, match nul ou les joueurs quittent la partie)

        do{

        mod++;

        // Le Joueur 1 joue en premier.
        if (mod%2!=0){

            // Affiche les informations du joueur 1.
        gotoligcol(3,97);
        printf("Joueur 1: %s\n",A);
        gotoligcol(5,97);
        printf("Jeton 1: %c\n", J1);
        gotoligcol(7,97);
        printf("Barrieres Restantes: %d\n",mur1);

            // Affiche le menu d'action du joueur.

        gotoligcol(24,0);
        menuaction= MenuAction();


        switch(menuaction)
        {
            initialisationDuPlat(plateau);
            // Permet au joueur de déplacer son jeton sur le plateau.
        case 1:

            // Saisie des coordonnées.

            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);

            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite\n");
            scanf("%d",&h);
            system("cls");
            // Convertie les coordonnées saisit par le joueur à l'aide des sous programme Ligne() et Colonne().

            i1=Ligne(LC);
            j1=Colonne(CC);

            // Verifie si la case est libre.

           // CASE_Libre(plateau, J)
            //Affiche le plateau avec la nouvelle position du jeton.


            Deplacer1B(  plateau , i1,  j1,i2,j2,J1,  J2,h);




            break;

        case 2:

            // Permet au joueur de placer des barrieres sur la plateau tant qu'il lui en reste.

            if (mur1>0)
            {

                // Le joueur saisit les coordonnees de sa barriere.
            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);
            system("cls");

                // Les coordonnees saisit son convertir à l'aide des sous programmes.

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

                // On affiche les barrieres sur le plateau.

            Barriere(plateau, ib1, jb1, ib2, jb2);


                // On fait un decompte de nombre de barriere du joueur.

            mur1=mur1-1;

            }
                // Si le joueur ne possede plus de barriere.
            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }

            break;

                // Le joueur veut passer son tour, il n'y a rien à faire.
        case 3:

            break;

                // Le joueur veut annuler son action.
        case 4:

                // On affiche à nouveau le plateau avec les anciennes coordonnees.


            break;

                //Le joueur souhaite quitter la partie, elle sera alors sauvegardée.

        case 5:

            sauvegarder_partie1( A, B, J1, J2, i1, j1, i2, j2);

            // On quitte le jeu.

            system("exit");

            break;

            // L'action choisit n'existe pas.
        default:
            printf("Action impossible!");

        }
        affichage_plateau(plateau);

        }



        // C'est au tour du Joueur 2 de jouer.
        else
        {

            //On affiche les donnees du Joueur 2.

            gotoligcol(3,97);
            printf("Joueur 2: %s\n",B);
            gotoligcol(5,97);
            printf("Jeton 2: %c\n", J2);
            gotoligcol(7,97);
            printf("Barrieres Restantes: %d\n",mur2);

            //On affiche le menu des actions possibles du joueur.

        gotoligcol(24,0);
        menuaction= MenuAction();


        switch(menuaction)
        {

        initialisationDuPlat(plateau);

                // Le joueur peut déplacer son jeton sur le plateau.
        case 1:

                // Le joueur saisit les coordonnees d'arriver de son jeton.
            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);
            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite");
            scanf("%d",&h);
            system("cls");

                // On convertit les coordonnees a l'aide des sous programmes.

            i2=Ligne(LC);
            j2=Colonne(CC);


                // On affiche le plateau avec la nouvelle position des jetons.


            Deplacer1B(  plateau , i1,  j1,i2,j2,J1,  J2,h);



            break;


            // Le joueur peut choisir de placer des barrieres sur le plateau.

        case 2:

            // Si le joueur possede des barrieres.

            if (mur2>0){


            // Le joueur saisit les coordonnees de ses barrieres.

            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);
            system("cls");

            // On convertit les coordonnees saisit à l'aide des sous programmes.

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

            // Verifie si la case est libre.

          //  CASE_Libre(plateau, J);

            // On affiche les barrieres sur la plateau.

            Barriere(plateau, ib1,jb1, ib2, jb2);


            // On realise un decompte des barrieres du joueur.
            mur2=mur2-1;

            }

            //Si le joueur n'as pas de barrieres, il ne peut pas en placer.

            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }


            break;

            // Le joueur veut passer son tour, il n'y a rien à faire.
        case 3:

            break;

            // Le joueur veut annuler son action.
        case 4:

            // On affiche le plateau avec les anciennes coordonnees.






            break;

            // Le joueur décide de quitter la plartie, elle sera alors sauvegardée.
        case 5:

            sauvegarder_partie1(A, B, J1, J2, i1, j1, i2, j2);

            // On quitte le jeu.

            system("exit");

            break;

            // L'action saisit n'existe pas.
        default:
            printf("Action impossible!");

        }affichage_plateau(plateau);

        }


        // Ces sous programmes permettent de detecter un gagnant.
        G2=Gagnant2(i2);
        G1=Gagnant1(i1);


        }while((G2!=1)&&(G1!=1)); // La boucle s'arrete lorqu'il y a un gagnant ou lorsqu'il y a un match nul. (ou sortie de jeu)

        // Si le gagnant est le Joueur 1 on lui ajoute 5 à son score.
        if (G1==1)
        {
            printf("\n      Le Joueur 1: %s GAGNE LA PARTIE\n",A);
            score1=score1+5;
        }

        // Si le Joueur 2 gagnent, on lui ajoute 5 à son score.
        else if (G2==1)
        {
            printf("\n      Le Joueur 2: %s GAGNE LA PARTIE\n",B);
            score2=score2+5;
        }

        // On sauvegarde les scores des joueures dans un fichier à la fin de la partie.

        sauvegarder_score(A,B,score1, score2);



    }









            // COMMENCE UNE PARTIE A 4 JOUEURS;

    else{

        //Saisie des noms.
        printf("Veuillez saisir le nom des quatre joueurs:\n");
        printf("            Pseudo 1:\n");
        scanf("%s",&nom1);
        printf("            Pseudo 2:\n");
        scanf("%s",&nom2);
        printf("            Pseudo 3:\n");
        scanf("%s",&nom3);
        printf("            Pseudo 4:\n");
        scanf("%s",&nom4);
        system("cls");



        //Ordre passage aleatoire de tout les joueurs (cette fonction fait buger nos codeblocks)

        /*
         strcpy(A,Ordre2(nom1, nom2, nom3, nom4));
        do{
            strcpy(B,Ordre2(nom1, nom2, nom3, nom4));
        }while(strcmp(A,B)==0);
        do{
            strcpy(C,Ordre2(nom1, nom2, nom3, nom4));
        }while((strcmp(A,C)==0)||(strcmp(B,C)==0));
        do{
            strcpy(D,Ordre2(nom1, nom2, nom3, nom4));
        }while((strcmp(A,D)==0)||(strcmp(B,D)==0)||(strcmp(C,D)==0));
        */






        // Ordre de passage des joueurs choisi aléatoirement.
        alea2=rand()%4;

        if(alea1==1){
            strcpy(A,nom1);
            strcpy(B,nom2);
            strcpy(C,nom3);
            strcpy(D,nom4);

        }
        else if (alea2==2){
            strcpy(A,nom2);
            strcpy(B,nom3);
            strcpy(C,nom4);
            strcpy(D,nom1);
        }
        else if (alea2==3){
            strcpy(A,nom3);
            strcpy(B,nom4);
            strcpy(C,nom1);
            strcpy(D,nom2);
        }
        else{
            strcpy(A,nom4);
            strcpy(B,nom1);
            strcpy(C,nom2);
            strcpy(D,nom3);
        }

        // Tirage des jetons de façon aléatoire.
        J1=Jeton();
        do{
            J2=Jeton();
        }while(J2==J1);
        do{
            J3=Jeton();
        }while((J3==J1)||(J3==J2));
        do{
            J4=Jeton();
        }while((J4==J1)||(J4==J2)||(J4==J3));

            //On affiche le plateau afin que les joueurs choisissent leurs positions de départ.

        initialisationDuPlat(plateau);
        affichage_plateau(plateau);

            // Les joueurs choisissent leurs coordonnees.
        printf("Joueur 1 veuillez choisir une case de depart sur la ligne 1:\n");
        scanf("%s",&D1);
        printf("Joueur 2 veuillez choisir une case de depart sur la colonne 17:\n");
        scanf("%d",&d2);
        printf("Joueur 3 veuillez choisir une case de depart sur la ligne 9:\n");
        scanf("%s",&D3);
        printf("Joueur 4 veuillez choisir une case de depart sur la colonne 1:\n");
        scanf("%d",&D4);


            // On convertit les coordonnees saisit à l'aide des sous programmes.

        j=Colonne(D1);
        i=Ligne(d2);
        jj=Colonne(D3);
        ii=Ligne(D4);
        system("cls");

            // On Affiche le plateau de départ.
        gotoligcol(3,0);
        Depart2(plateau,j, i, jj, ii, J1, J2, J3, J4);
        i2=i;
        j2=17;
        i3=17;
        j3=jj;
        i4=ii;
        j4=1;


                // Permet de faire jouer les 4 joueurs chacuns leurs tours jusqu'à la fin de la partie ( gagnant, match nul, quitte la partie).

        do{

        mod++;

                // Le joueur 1 commence la Partie.

        if (mod%4==1){
            // On affiche les informations du joueur 1.
        gotoligcol(3,97);
        printf("Joueur 1: %s\n",A);
        gotoligcol(5,97);
        printf("Jeton 1: %c\n", J1);
        gotoligcol(7,97);
        printf("Barrieres Restantes: %d\n",mur1b);

            // On affiche les actions possible du joueur.

        gotoligcol(24,0);
        menuaction= MenuAction();


        switch(menuaction)
        {
            initialisationDuPlat(plateau);

            // Le joueur peut déplacer son pions.
        case 1:

            // Le joueur saisit les coordonnees d'arrivées de son pion.

            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);
            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite\n");
            scanf("%d",&g);
            system("cls");
            system("cls");

            // On convertit les coordonnees avec des sous programmes.

            i1=Ligne(LC);
            j1=Colonne(CC);

            // Verifie si la case est libre.

//            CASE_Libre(plateau, J);

            //On affiche le plateau avec la nouvelle position du jeton.

            //initialisationDuPlat(plateau); On le met en commentaire afin de laisser les barrieres visibles sur le plateau.
            Deplacer2(plateau, i1, j1, i2,  j2, i3, j3, i4, j4,J1,J2, J3, J4, g);

            break;


            // Le joueur peut placer des barrieres tant qu'il en a.

        case 2:

            // Si le joueurs possede des barrieres.

            if(mur1b>0){

                    // Le joueur saisit les coordonnees des barrieres.

            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);

            system("cls");

                // On convertit les coordonnees avec des sous programmes.

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

                // On affiche les barrieres sur le plateau.

            Barriere(plateau, ib1,jb1, ib2, jb2);


                // On fait un decompte des barrieres du joueur.
            mur1b=mur1b-1;

            }

                // Si le joueur n'as pas de barriere il ne peut pas en placer.

            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }


            break;

                // Le joueur veut passer son tour, il n'y a rien à faire.
        case 3:

            break;

                // Le joueur veut annuler son action.
        case 4:

            // On affiche le plateau avec les anciennes coordonnees.

            break;

            // Le joueur souhaite quitter la partie, elle sera alors sauvegardée.
        case 5:

            sauvegarder_partie2(nom1,nom2, nom3, nom4, J1, J2, J3,  J4, i1, j1, i2, j2, i3, j3, i4, j4);

            // On quitte le jeu.
            system("exit");

            break;

            // L'action saisit n'existe pas.
        default:
            printf("Action impossible!");

        }
        affichage_plateau(plateau);

        }

            // C'est au tour du joueur 2.
        else if(mod%4==2)
        {
            gotoligcol(3,97);
            printf("Joueur 2: %s\n",B);
            gotoligcol(5,97);
            printf("Jeton 2: %c\n", J2);
            gotoligcol(7,97);
            printf("Barrieres Restantes: %d\n",mur2b);

        gotoligcol(24,0);
        menuaction= MenuAction();


        switch(menuaction)
        {
            initialisationDuPlat(plateau);
        case 1:

            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);
            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite\n");
            scanf("%d",&g);
            system("cls");
            system("cls");

            i2=Ligne(LC);
            j2=Colonne(CC);

            // Verifie si la case est libre.

//            CASE_Libre(plateau, J);


            Deplacer2(plateau, i1, j1, i2,  j2, i3, j3, i4, j4,J1,J2, J3, J4, g);


            break;

        case 2:

            if (mur2b>0){

            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);
            system("cls");

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

            Barriere(plateau, ib1,jb1, ib2, jb2);


            }
            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }




            break;

            // Le joueur souhaite passer son tour, il n'y a rien a faire.
        case 3:

            break;

            // Le joueur souhaite annuler son action.
        case 4:

            // On affiche le tableau avec les anciennes coordonnees.

            break;

            // Le joueur souhaite quitter la partie, elle sera alors sauvegardée.

        case 5:

            sauvegarder_partie2(nom1,nom2, nom3, nom4, J1, J2, J3,  J4, i1, j1, i2, j2, i3, j3, i4, j4);

            // On quitte le jeu.
            system("exit");

            break;

            // L'action choisit n'existe pas.
        default:
            printf("Action impossible!");

        }
        affichage_plateau(plateau);


        }

            // C'est au tour du Joueur 3

        else if(mod%4==3)
        {
            gotoligcol(3,97);
            printf("Joueur 3: %s\n",C);
            gotoligcol(5,97);
            printf("Jeton 3: %c\n", J3);
            gotoligcol(7,97);
            printf("Barrieres Restantes: %d\n",mur3);

            gotoligcol(24,0);
            menuaction= MenuAction();


        switch(menuaction)
        {

            initialisationDuPlat(plateau);
        case 1:

            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);
            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite\n");
            scanf("%d",&g);
            system("cls");
            system("cls");
            i3=Ligne(LC);
            j3=Colonne(CC);

            // Verifie si la case est libre.

          //  CASE_Libre(plateau, J);


            Deplacer2(plateau, i1, j1, i2,  j2, i3, j3, i4, j4,J1,J2, J3, J4, g);



            break;

        case 2:


            if (mur3>0){
            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);
            system("cls");

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

            Barriere(plateau, ib1,jb1, ib2, jb2);
            affichage_plateau(plateau);
            mur3=mur3-1;
            }

            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }



            break;

            // Le joueur souhaite passer son tour, il n'y a rien à faire.
        case 3:

            break;

            // Le joueur souhaite annuler son action.
        case 4:
            // On affiche le plateau avec les anciennes coordonnees.

            break;

            // Le joueur souhaite quitter la partie, elle sera alors sauvegardée.
        case 5:

            sauvegarder_partie2(nom1,nom2, nom3, nom4, J1, J2, J3,  J4, i1, j1, i2, j2, i3, j3, i4, j4);

            // On quitte le jeu.
            system("exit");
            break;

            //L'action saisit n'existe pas.
        default:
            printf("Action impossible!");

        }
        affichage_plateau(plateau);


            // C'est au tour du Joueur 4.
        }else if(mod%4==0)
        {
            gotoligcol(3,97);
            printf("Joueur 4: %s\n",D);
            gotoligcol(5,97);
            printf("Jeton 4: %c\n", J4);
            gotoligcol(7,97);
            printf("Barrieres Restantes: %d\n",mur4);

        gotoligcol(24,0);
        menuaction= MenuAction();


        switch(menuaction)
        {initialisationDuPlat(plateau);
        case 1:

            printf("Veuillez saisir les coordonnees de la case:\n");
            printf("\n  Colonne Case:   ");
            scanf("%s",&CC);
            printf("  Ligne Case:   ");
            scanf("%d",&LC);
            printf(" 2- Bas\n 4-Gauche\n 8-Haut\n 6-Droite\n");
            scanf("%d",&g);
            system("cls");
            system("cls");
            i4=Ligne(LC);
            j4=Colonne(CC);

            // Verifie si la case est libre.

            //            CASE_Libre(plateau, J);


            Deplacer2(plateau, i1, j1, i2,  j2, i3, j3, i4, j4,J1,J2, J3, J4, g);



            break;

        case 2:

            if (mur4>0){

            printf("\n\n Veuillez saisir les coordonnees de la barriere.\n");
            printf("\n  Colonne case 1:   ");
            scanf("%s",&c1);
            printf("\n  Ligne case 1:   ");
            scanf("%s",&ll);
            printf("\n  Colonne case 2:   ");
            scanf("%s",&c2);
            printf("\n  Ligne case 2:   ");
            scanf("%s",&l2);
            system("cls");

            ib1=LigneB(ll);
            jb1=ColonneB(c1);
            ib2=LigneB(l2);
            jb2=ColonneB(c2);

            Barriere(plateau, ib1,jb1, ib2, jb2);
            affichage_plateau(plateau);
            mur4=mur4-1;
            }

            else {
            printf("Tu n'as plus de barrieres disponible! :(");
            }






            break;

            // Le joueur souhaite passer son tour, il n'y a rien à faire.
        case 3:

            break;

            // Le joueur souhaite annuler son action.
        case 4:

            // On affiche le plateau avec les anciennes coordonnees.

            break;

            // Le joueur souhaite quitter la partie, elle sera alors sauvegardée.
        case 5:
            sauvegarder_partie2(nom1,nom2, nom3, nom4, J1, J2, J3,  J4, i1, j1, i2, j2, i3, j3, i4, j4);



            // On quitte le jeu.
            system("exit");
            break;

            // L'action saisit n'existe pas.
        default:
            printf("Action impossible!");

        }
        affichage_plateau(plateau);


        }

            // Ces sous programmes permettent de detecter si il y a un gagnant.
        G1=Gagnant1(i1);
        G2=Gagnant2b(j2);
        G3=Gagnant3(i3);
        G4=Gagnant4(j4);


        }while((G1!=1)&&(G2!=1)&&(G3!=1)&&(G4!=1)); // La boucle s'arrete lorqu'il y a un gagnant (ou match nul ou qu'un joueur quitte la partie).


        // Si le Joueur 1 gagne la partie, il obtient +5.
        if (G1==1)
        {
            printf("\n      Le Joueur 1: %s GAGNE LA PARTIE\n",A);
            score1=score1+5;
        }

        // Si le Joueur 2 gagne la partie, il obtient + 5.
        else if (G2==1)
        {
            printf("\n      Le Joueur 2: %s GAGNE LA PARTIE\n",B);
            score2=score2+5;
        }

        // Si le joueur 3 gagne la partie, il obtient +5.
        else if (G3==1)
        {
            printf("\n      Le Joueur 3: %s GAGNE LA PARTIE\n",C);
            score3=score3+5;
        }

        // Si le joueur 4 gagne la partie, il obtient +5.
        else if (G4==1)
        {
            printf("\n      Le Joueur 4: %s GAGNE LA PARTIE\n",D);
            score4=score4+5;
        }

        // Les scores de tous les joueurs sont sauvegardés dans un fichier à la fin d'une partie.
        sauvegarder_score2(A, B, C, D, score1, score2, score3, score4);

    }


        break;



            //REPREND UNE PARTIE SAUVEGARDER.
    case 2:

        partie(plateau);

        break;



            //AFFICHER LES REGLES DU JEU.
    case 3:

        Aide_Menu();


        break;


            // AFFICHER LE SCORE DES JOUEURS.
    case 4:

        score();

        break;




            // QUITTER LE JEU.
    case 5:
        printf("\n\n        ***Game Over****");
        //quitte le jeu.
        system("exit");
    break;


        // Le choix saisit n'existe pas.

    default:
        printf("Ce choix n'existe pas\n");
    }

    }while(menu!=5); //La boucle continue tant que l'on ne quitte pas le Jeu.


    return 0;
    // FIN DU PROGRAMME
}

