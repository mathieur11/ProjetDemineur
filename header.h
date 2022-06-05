#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef COULEURS
#define COULEURS

#define clrscr() printf("\033[H\033[2J")

#define couleur(param) printf("\033[%sm", param)

#endif

#define NOIR "30"
#define ROUGE "31"
#define VERT "32"
#define JAUNE "33"
#define BLEU "34"
#define MAGENTA "35"
#define CYAN "36"
#define BLANC "37"

int minesAutour9(char tab[9][9], int i, int j);
int minesAutour16(char tab[16][16], int i, int j);
void afficheGrille9(char plateau[9][9]);
void afficheGrilleDefaite9(char plateau[9][9]);
void afficheGrille16(char plateau[16][16]);
void afficheGrilleDefaite16(char plateau[16][16]);
void poseMines16(char plateau[16][16]);
void poseMines9(char plateau[9][9]);
int correctCase9(int i, int j);
int correctCase16(int i, int j);
void devoilerAutour9(char plateau[9][9], int i, int j);
void devoilerAutour16(char plateau[16][16], int i, int j);
int devoilerCase9(char plateau[9][9], int i, int j);
int devoilerCase16(char plateau[16][16], int i, int j);
int placerDrapeau16(char plateau[16][16], int i, int j);
int placerDrapeau9(char plateau[9][9], int i, int j);
void vide_scanf();
int ecrireScore(char *pseudo, int h, int min, int s, char *niveau);
int winCondition9(char plateau[9][9], int t1, char *pseudo);
int winCondition16(char plateau[16][16], int t1, char *pseudo);
char conversionMinMaj(char d);
int main();
