#include "header.h"

// Toutes ces fonctions sont pour le niveau "facile".

// dévoile tout les 0 autours de la case contenant un 0.
void devoilerAutour9(char plateau[9][9], int i, int j) {
  if (plateau[i][j] == '0') {
    for (int k = -1; k < 2; k++) {
      for (int p = -1; p < 2; p++) {// les deux for permettent de faire le tour de la case et de vérifier autour.
        if (correctCase9(i + k, j + p)) {
          if (plateau[i + k][j + p] < '0') {
            plateau[i + k][j + p] = plateau[i + k][j + p] + 10;// passe d'une valeur ASCII inférieur à '0' à une valeur correspondant au '0' pour ensuite l'afficher.
            devoilerAutour9(plateau, i + k, j + p); // récursivité pour continuer s'il y a eu une case découverte égal à '0'.
          }
        }
      }
    }
  }
}

// Vérifie si la case appartient bien au plateau de jeu.
int correctCase9(int i, int j) {
  if (i >= 0 && i < 9) {
    if (j >= 0 && j < 9) {
      return 1;
    }
  }
  return 0;
}

//dévoile la case saisie par l'utillisateur.
int devoilerCase9(char plateau[9][9], int i, int j) {
  if (plateau[i][j] >= '0' && plateau[i][j] <= '8') {
    printf("Cette case a déja été découverte.");
    afficheGrille9(plateau);
    return 0;
  } 
  else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) {
    printf("Enlever d'abord le drapeau de cette case avant de la dévoiler\n\n");
    return 0;
  } 
  else if (plateau[i][j] < '0' && plateau[i][j] > '%') {
    plateau[i][j] = plateau[i][j] + 10; 
    devoilerAutour9(plateau, i, j);
    afficheGrille9(plateau);
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
int placerDrapeau9(char plateau[9][9], int i, int j) {
  if (plateau[i][j] >= '0' && plateau[i][j] <= '8') {
    printf("Vous ne pouvez pas placer de drapeau sur une case découverte.\n\n");
    return 0;
  } 
  else if ((plateau[i][j] > 57 && plateau[i][j] < 67) || plateau[i][j] == 97) {
    plateau[i][j] = plateau[i][j] - 20;
    afficheGrille9(plateau);
  } 
  else {
    plateau[i][j] = plateau[i][j] + 20;
    afficheGrille9(plateau);
  }
  return 1;
}

// Détermine quand le joueur a remporté la partie.
int winCondition9(char plateau[9][9], int t1, char *pseudo) {
  int compt = 0, compt2 = 0;
  int t2, s, min, h;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if ((plateau[i][j] < 57 && plateau[i][j] > 47) || plateau[i][j] == 97 || plateau[i][j] == 77) { // calcule si toutes les cases sont découvertes et qu'il ne reste que des mines ou des drapeaux sur les mines.
        compt++;
      }
      if (plateau[i][j] == 97) { // calcule si toutes les mines ont des drapeaux posé dessus.
        compt2++;
      }
      else if (plateau[i][j]>57 && plateau[i][j]<67){
        compt2--; // pour éviter de gagner en placant des drapeaux partout.
      }
    }
  }
  if (compt == 81 || compt2 == 10) { // 81 correspond au nombre total des cases de la grille et 10 au nombre total de mines.
    printf("VICTOIIIRE !!!!!!!!!!!\n\n");
    t2 = time(NULL); // prend un certain temps en secondes.
    s = t2 - t1; // soustrait le temps de la fin au temps du début pour déterminer le temps que le joueur a pris pour gagner.
    if (s > 60) { // convertit les secondes en minutes et heures.
      min = s / 60;
      h = min / 60;
      s = s % 60;
      min = min % 60;
    }
    if (h != 0) {
      printf("Votre temps est de %d heure(s) %d minute(s) %d seconde(s).\n\n", h, min, s);
    } 
    else if (min != 0) {
      printf("Votre temps est de %d minute(s) %d seconde(s).\n\n", min, s);
    } 
    else {
      printf("Votre temps est de %d secondes.\n\n", s);
    }
    ecrireScore(pseudo, h, min, s, "facile");
    return 1;
  } 
  else {
    return 0;
  }
}
