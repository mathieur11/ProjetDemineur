#include "header.h"

int main() {
	clrscr();
  printf("DDD  EEEE M   M III N   N EEEE U   U RRRR\nD  D E    MM MM  I  NN  N E    U   U R   R\nD  D EEE  M M M  I  N N N EEE  U   U RRRR\nD  D E    M   M  I  N  NN E    U   U R R\nDDD  EEEE M   M III N   N EEEE  UUU  R  RR\n\n");
  char plateau16[16][16] = {[0 ... 15][0 ... 15] = '9'};
  char plateau9[9][9] = {[0 ... 8][0 ... 8] = '9'};
  char pseudo[100]; // grand tableau 2D dans le cas où le joueur rentre un grand pseudo.
  int dif, action, i, a, b, t1;
  char j;
  srand(time(NULL)); // est obligatoire pour utiliser la fonction 'time(NULL)' pour t1 et t2.
	do{
  	printf("\nQuel est votre pseudo ?\n");
  	a = scanf("%s", pseudo);
		}while (a!= 1);
  do {
    printf("A quel niveau de difficulté souhaitez-vous jouer ?\n1 = Facile\n2 = Difficile\n");
    a = scanf("%d", &dif);
    vide_scanf();
  } while ((dif != 1 && dif != 2) || a != 1); // le a prend 1 si le joueur a bien rentré un chiffre.
  if (dif == 1) {
    poseMines9(plateau9);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        minesAutour9(plateau9, i, j);// calcule immédiatemment les valeurs de chaque case qui seront ensuite caché pour éviter d'avoir à le faire à chaque tour.
      }
    }
    afficheGrille9(plateau9);
    t1 = time(NULL); // prend un certain temps en secondes.
    do {
      do {
        printf("Que voulez-vous faire ?\n1 = Découvrir une case\n2 = Placer un drapeau\n");
        a = scanf("%d", &action);
        vide_scanf();
      } while ((action != 1 && action != 2) || a != 1);
      if (action == 1) {
        do {
          printf("Quelle case souhaitez-vous découvrir ? Saisir la colonne puis la ligne.\n");
          a = scanf("%c", &j);
          vide_scanf();
          j = conversionMinMaj(j);
          b = scanf("%d", &i);
          vide_scanf();
        } while (i < 1 || i > 9 || j < 'A' || j > 'I' || a != 1 || b != 1);
        if (devoilerCase9(plateau9, i - 1, j - 65)) { // i-1 car la grille commence à 1 et non 0, j-65 car j est un char et il faut un int.
          afficheGrilleDefaite9(plateau9);
          return 0;
        }
      } 
      else if (action == 2) {
        do {
          printf("Sur quelle case souhaitez-vous placer un drapeau ? Saisir la colonne puis la ligne.\nPour retirer un drapeau, selectionner cette case.\n");
          a = scanf("%c", &j);
          vide_scanf();
          j = conversionMinMaj(j);
          b = scanf("%d", &i);
          vide_scanf();
        } while (i < 1 || i > 9 || j < 'A' || j > 'I' || placerDrapeau9(plateau9, i - 1, j - 65) == 0 || a != 1 || b != 1);
      }
    } while (winCondition9(plateau9, t1, pseudo) == 0);
  }
  else if (dif == 2) {
    poseMines16(plateau16);
    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 16; j++) {
        minesAutour16(plateau16, i, j);
      }
    }
    afficheGrille16(plateau16);
    t1 = time(NULL); // prend un certain temps en secondes.
    do {
      do {
        printf("Que voulez-vous faire ?\n1 = Découvrir une case\n2 = Placer un drapeau\n");
        a = scanf("%d", &action);
        vide_scanf();
      } while ((action != 1 && action != 2) || a != 1);
      if (action == 1) {
        do {
          printf("Quelle case souhaitez-vous découvrir ? Saisir la colonne puis la ligne.\n");
          a = scanf("%c", &j);
          vide_scanf();
          j = conversionMinMaj(j);
          b = scanf("%d", &i);
          vide_scanf();
        } while (i < 1 || i > 16 || j < 'A' || j > 'P' || a != 1 || b != 1);
        if (devoilerCase16(plateau16, i - 1, j - 65)) {
          afficheGrilleDefaite16(plateau16);
          return 0;
        }
      } 
      else if (action == 2) {
        do {
          printf("Sur quelle case souhaitez-vous placer un drapeau ? Saisir la colonne puis la ligne.\nPour retirer un drapeau, selectionner cette case.\n");
          a = scanf("%c", &j);
          vide_scanf();
          j = conversionMinMaj(j);
          b = scanf("%d", &i);
          vide_scanf();
        } while (i < 1 || i > 16 || j < 'A' || j > 'P' ||
                 placerDrapeau16(plateau16, i - 1, j - 65) == 0 || a != 1 || b != 1);
      }
    } 
    while (winCondition16(plateau16, t1, pseudo) == 0);
  }
}
