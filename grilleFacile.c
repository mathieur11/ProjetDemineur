#include "header.h"

// Toutes ces fonctions sont pour le niveau "facile".

// Indiquer les mines autour de la case dévoilée.
int minesAutour9(char tab[9][9], int i, int j) {
  int nmb = 0;
  if (tab[i][j] == 'M') { // 'M' = une mine.
    return 1;
  } 
  else {
    if (i == 0) {
      if (j == 0) {
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j + 1] == 'M') {
          nmb++;
        }
      } 
      else if (j == 8) {
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
      } 
      else {
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j + 1] == 'M') {
          nmb++;
        }
      }
    } 
    else if (i == 8) {
      if (j == 0) {
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
      } 
      else if (j == 8) {
        if (tab[i - 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
      } 
      else {
        if (tab[i - 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
      }
    } 
    else {
      if (j == 0) {
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
      } 
      else if (j == 8) {
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
      } 
      else {
        if (tab[i - 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j] == 'M') {
          nmb++;
        }
        if (tab[i - 1][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i][j + 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j - 1] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j] == 'M') {
          nmb++;
        }
        if (tab[i + 1][j + 1] == 'M') {
          nmb++;
        }
      }
    }

    tab[i][j] = nmb + 38; // voir table ASCII, correspond aux valeurs entre (0 et 8) - 10 afin d'ensuite caché ces cases qui ne seront pas encore découvertes.
    return 1;
  }
}

 // Affichage d'un plateau.
void afficheGrille9(char plateau[9][9]) {
  int i, j, k;
  clrscr();// permet d'"effacer" l'écran dans le terminal.
  printf("\nVoici votre grille actuelle : \n\n");
  printf("   A B C D E F G H I\n");
  for (i = 0; i < 9; i++) {
    k = i + 1; // le k correspond aux numéros des lignes.
    printf("%d ", k);
    for (j = 0; j < 9; j++) {
      printf("|");
      if (plateau[i][j] > '0' && plateau[i][j] < '9') {
        if (plateau[i][j] == '1') {
          couleur(CYAN); // permet d'afficher dans une certaine couleur.
          printf("%c", plateau[i][j]);
          couleur("0"); // remet la couleur à son origine pour la suite.
        } 
        else if (plateau[i][j] == '2') {
          couleur(VERT);
          printf("%c", plateau[i][j]);
          couleur("0");
        } 
        else if (plateau[i][j] == '3') {
          couleur(JAUNE);
          printf("%c", plateau[i][j]);
          couleur("0");
        } 
        else {
          couleur(ROUGE);
          printf("%c", plateau[i][j]);
          couleur("0");
        }
      } 
      else if (plateau[i][j] == '0') {
        printf(" ");
      }
      else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) { // correspond aux valeurs ASCII s'il y a un drapeau (voir fonction placerDrapeau).
        couleur("43");
        printf("*");
        couleur("0");
      } 
      else {
        printf("@"); // Si la valeur ASCII d'une case est donc inférieur à la valeur du '0' ou égale à 'M' (une mine), cette case est caché par un '@'.
      }
    }
    printf("|");
    printf("\n");
  }
  printf("\n");
}

// Affiche la grille non cachée en cas de défaite.
void afficheGrilleDefaite9(char plateau[9][9]) {
  int i, j, k;
  printf("   A B C D E F G H I\n");
  for (i = 0; i < 9; i++) {
    k = i + 1;
    printf("%d ", k);
    for (j = 0; j < 9; j++) {
      printf("|");
      if (plateau[i][j] < 48) {
        plateau[i][j] = plateau[i][j] + 10; // le +10 permet de passer à des caractères entre 0 et 8.
      }
      if (plateau[i][j] > 57 && plateau[i][j] < 77) {
        plateau[i][j] = plateau[i][j] - 10; // le -10 permet de passer des valeurs ASCII pour des drapeaux aux valeurs ASCII entre 1 et 10.
      }
      if (plateau[i][j] == 97) {
        plateau[i][j] = plateau[i][j] - 20; // le -20 permet de passer d'une valeur ASCII pour des drapeaux à une valeur ASCII pour les mines.
      }
      if (plateau[i][j] == '0') {
        printf(" ");
      } 
      else if (plateau[i][j] == '1') { // puis on met les couleurs pour l'affichage.
        couleur(CYAN);
        printf("%c", plateau[i][j]);
        couleur("0");
      } 
      else if (plateau[i][j] == '2') {
        couleur(VERT);
        printf("%c", plateau[i][j]);
        couleur("0");
      } 
      else if (plateau[i][j] == '3') {
        couleur(JAUNE);
        printf("%c", plateau[i][j]);
        couleur("0");
      } 
      else if (plateau[i][j] > '3' && plateau[i][j] < '9') {
        couleur(ROUGE);
        printf("%c", plateau[i][j]);
        couleur("0");
      } 
      else if (plateau[i][j] == 'M') {
        couleur("41");
        printf("%c", plateau[i][j]);
        couleur("0");
      } 
      else {
        printf("%c", plateau[i][j]);
      }
    }
    printf("|");
    printf("\n");
  }
  printf("\n");
}

// Pose des mines.
void poseMines9(char plateau[9][9]) {
  int nmb, i, j;
  nmb = 10;
  while (nmb > 0) {
    i = rand() % 9; // sélectionne un nombre aléatoire entre 0 et 15.
    j = rand() % 9;
    if (plateau[i][j] == 'M') {
      nmb++;
    } 
    else {
      plateau[i][j] = 'M';
    }
    nmb = nmb - 1;
  }
}
