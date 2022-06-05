#include "header.h"

// Pour avoir le maximum de commentaires sur les fonctions, lire d'abord les fonctions pour le niveau "facile".
// Toutes ces fonctions sont pour le niveau "difficile".

// dévoile tous les 0 autours de la case contenant un 0.
void devoilerAutour16(char plateau[16][16], int i, int j) {
  if (plateau[i][j] == '0') {
    for (int k = -1; k < 2; k++) {
      for (int p = -1; p < 2; p++) {
        if (correctCase16(i + k, j + p)) {
          if (plateau[i + k][j + p] < '0') {
            plateau[i + k][j + p] = plateau[i + k][j + p] + 10;
            devoilerAutour16(plateau, i + k, j + p);
          }
        }
      }
    }
  }
}

// Vérifie si la case appartient bien au plateau de jeu.
int correctCase16(int i, int j) {
  if (i >= 0 && i < 16) {
    if (j >= 0 && j < 16) {
      return 1;
    }
  }
  return 0;
}

//dévoile la case saisie par l'utillisateur.
int devoilerCase16(char plateau[16][16], int i, int j) {
  if (plateau[i][j] >= '0' && plateau[i][j] <= '8') {
    printf("Cette case a déja été découverte.");
    afficheGrille16(plateau);
    return 0;
  } 
  else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) {
    printf("Enlever d'abord le drapeau de cette case avant de la dévoiler\n\n");
    return 0;
  } 
  else if (plateau[i][j] < '0' && plateau[i][j] > '%') {
    plateau[i][j] = plateau[i][j] + 10;
    devoilerAutour16(plateau, i, j);
    afficheGrille16(plateau);
    return 0;
  }
  if (plateau[i][j] == 'M') {
    clrscr();
    printf("BOOOOM !!! Vous avez perdu...\n\n Voila où était les bombes !\n\n");
    return 1;
  }
	return 0;
}

// Permet de placer un drapeau sur la case choisie.
int placerDrapeau16(char plateau[16][16], int i, int j) {
  if (plateau[i][j] >= '0' && plateau[i][j] <= '8') {
    printf("Vous ne pouvez pas placer de drapeau sur une case découverte.\n\n");
    return 0;
  } 
  else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) {
    plateau[i][j] = plateau[i][j] - 20;
    afficheGrille16(plateau);
  } 
  else {
    plateau[i][j] = plateau[i][j] + 20;
    afficheGrille16(plateau);
  }
  return 1;
}

// Détermine quand le joueur a remporté la partie.
int winCondition16(char plateau[16][16], int t1, char *pseudo) {
  int compt = 0, compt2 = 0;
  int t2, s, min, h;
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      if ((plateau[i][j] < 57 && plateau[i][j] > 47) || plateau[i][j] == 97 ||
          plateau[i][j] == 77) {
        compt++;
      }
      if (plateau[i][j] == 97) {
        compt2++;
      }
      else if (plateau[i][j]>57 && plateau[i][j]<67){
        compt2--;
      }
    }
  }
  if (compt == 256 || compt2 == 40) { // 256 correspond au nombre total des cases de la grille et 40 au nombre total de mines.
    printf("VICTOIIIRE !!!!!!!!!!!\n\n");
    t2 = time(NULL);
    s = t2 - t1;
    if (s > 60) {
      min = s / 60;
      h = min / 60;
      s = s % 60;
      min = min % 60;
    }
    if (h != 0) {
      printf("Votre temps est de %d heure(s) %d minute(s) %d seconde(s).\n\n",
             h, min, s);
    } 
    else if (min != 0) {
      printf("Votre temps est de %d minute(s) %d seconde(s).\n\n", min, s);
    } 
    else {
      printf("Votre temps est de %d secondes.\n\n", s);
    }
    ecrireScore(pseudo, h, min, s, "difficile");
    return 1;
  } 
  else {
    return 0;
  }
}
