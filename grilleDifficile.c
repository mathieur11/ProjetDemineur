#include "header.h"

// Pour avoir le maximum de commentaires sur les fonctions, lire d'abord les fonctions pour le niveau "facile".
// Toutes ces fonctions sont pour le niveau "difficile".

// Indiquer les mines autour de la case dévoilée.
int minesAutour16(char tab[16][16], int i, int j) {
  int nmb = 0;
  if (tab[i][j] == 'M') {
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
      else if (j == 15) {
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
    else if (i == 15) {
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
      else if (j == 15) {
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
      else if (j == 15) {
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
void afficheGrille16(char plateau[16][16]) {
  int i, j, k;
  clrscr();
  printf("\nVoici votre grille actuelle : \n\n");
  printf("   A B C D E F G H I J K L M N O P\n");
  for (i = 0; i < 16; i++) {
    k = i + 1;
    if (k < 10) {
      printf("%d ", k);
      for (j = 0; j < 16; j++) {
        printf("|");
        if (plateau[i][j] > '0' && plateau[i][j] < '9') {
          if (plateau[i][j] == '1') {
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
          else {
            couleur(ROUGE);
            printf("%c", plateau[i][j]);
            couleur("0");
          }
        } 
        else if (plateau[i][j] == '0') {
          printf(" ");
        } 
        else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) { // correspond aux données s'il y a un drapeau (voir fonction placerDrapeau).
          couleur("43");
          printf("*");
          couleur("0");
        } 
        else {
          printf("@");
        }
      }
      printf("|");
    } 
    else { // décomposé en 2 car il faut mettre un espace entre les valeurs de 1 à 9 et le '|' mais il n'en faut pas pour les valeurs de 10 à 16.
      printf("%d", k);
      for (j = 0; j < 16; j++) {
        printf("|");
        if (plateau[i][j] > '0' && plateau[i][j] < '9') {
          if (plateau[i][j] == '1') {
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
          else {
            couleur(ROUGE);
            printf("%c", plateau[i][j]);
            couleur("0");
          }
        } 
        else if (plateau[i][j] == '0') {
          printf(" ");
        } 
        else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) { // correspond aux données s'il y a un drapeau (voir fonction placerDrapeau).
          couleur("43");
          printf("*");
          couleur("0");
        } 
        else {
          printf("@");
        }
      }
      printf("|");
    }
    printf("\n");
  }
  printf("\n");
}

// Affiche la grille non cachée en cas de défaite.
void afficheGrilleDefaite16(char plateau[16][16]) {
  int i, j, k;
  printf("   A B C D E F G H I J K L M N O P\n");
  for (i = 0; i < 16; i++) {
    k = i + 1;
    if (k < 10) {
      printf("%d ", k);
      for (j = 0; j < 16; j++) {
        printf("|");
        if (plateau[i][j] < 48) {
          plateau[i][j] = plateau[i][j] + 10;
        }
        if (plateau[i][j] > 57 && plateau[i][j] < 77) {
          plateau[i][j] = plateau[i][j] - 10;
        }
        if (plateau[i][j] == 97) {
          plateau[i][j] = plateau[i][j] - 20;
        }
        if (plateau[i][j] == '0') {
          printf(" ");
        } 
        else if (plateau[i][j] == '1') {
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
    }
    if (k >= 10) {
      printf("%d", k);
      for (j = 0; j < 16; j++) {
        printf("|");
        if (plateau[i][j] < 48) {
          plateau[i][j] = plateau[i][j] + 10;
        }
        if (plateau[i][j] > 57 && plateau[i][j] < 77) {
          plateau[i][j] = plateau[i][j] - 10;
        }
        if (plateau[i][j] == 97) {
          plateau[i][j] = plateau[i][j] - 20;
        }
        if (plateau[i][j] == '0') {
          printf(" ");
        } 
        else if (plateau[i][j] == '1') {
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
    }
    printf("\n");
  }
  printf("\n");
}

// Pose des mines.
void poseMines16(char plateau[16][16]) {
  int nmb, i, j;
  nmb = 40; // nombre de mines total.
  while (nmb > 0) {
    i = rand() % 16; // sélectionne un nombre aléatoire entre 0 et 15.
    j = rand() % 16;
    if (plateau[i][j] == 'M') {
      nmb++;// ajoute 1 au nombre de mines si la case sélectionné est déja équipé d'une mine.
    } 
    else {
      plateau[i][j] = 'M';// equipe la case d'une mine.
    }
    nmb = nmb - 1;
  }
}
