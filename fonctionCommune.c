#include "header.h"

// permet de vider le scanf pour éviter qu'une lettre fasse bugger le programme lorsqu'on attend un chiffre.
void vide_scanf() {
  char c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

// écris le score dans un fichier.
int ecrireScore(char *pseudo, int h, int min, int s, char *niveau) {
  FILE *fichier = NULL;
	char score[999];
	char *a;
	fichier = fopen("highScore.txt", "r+");
  if (fichier == NULL) {
    printf("Erreur d'allocation\n");
    exit(1);
  }
  do{
    fseek(fichier, -1, SEEK_CUR); // déplace le curseur dans le fichier d'1 vers la gauche car fgetc le déplace d'1 vers la droite.
    a = fgets(score, 200, fichier);
    printf("%s", score); // écris les anciens scores des autres joueurs.
  }while(fgetc(fichier) != EOF || a == NULL);
  fclose(fichier);
	fichier = NULL;
  fichier = fopen("highScore.txt", "a"); // ouvre le fichier highScore et le crée s'il n'existe pas.
  if (fichier == NULL) {
    printf("Erreur d'allocation\n");
    exit(1);
  }
  if (h != 0) {
    fprintf(fichier, "%s a mis %d heure(s), %d minute(s) et %d seconde(s) pour réussir le niveau %s.\n", pseudo, h, min, s, niveau); // écris dans le fichier.
  } 
  else if (min != 0) {
    fprintf(fichier, "%s a mis %d minute(s) et %d seconde(s) pour réussir le niveau %s.\n", pseudo, min, s, niveau);
  } 
  else {
    fprintf(fichier, "%s a mis %d seconde(s) pour réussir le niveau %s.\n", pseudo, s, niveau);
  }
  fclose(fichier); // ferme le fichier.
	return 0;
}

char conversionMinMaj(char d){ // convertit les minuscules en majuscules au cas où le joueur rentre une minuscule lorsqu'on lui demande une lettre.
  if(d>96 && d<123){
    d = d-32;
  }
    return d;
}
