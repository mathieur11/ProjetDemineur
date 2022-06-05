all : jeu

main.o : main.c header.h
	gcc -c main.c -o main.o

fonctionCommune.o : fonctionCommune.c header.h
	gcc -c fonctionCommune.c -o fonctionCommune.o

grilleDifficile.o : grilleDifficile.c header.h
	gcc -c grilleDifficile.c -o grilleDifficile.o

grilleFacile.o : grilleFacile.c header.h
	gcc -c grilleFacile.c -o grilleFacile.o

userPlayDiff.o : userPlayDiff.c header.h
	gcc -c userPlayDiff.c -o userPlayDiff.o

userPlayFac.o : userPlayFac.c header.h
	gcc -c userPlayFac.c -o userPlayFac.o

jeu : main.o fonctionCommune.o grilleDifficile.o grilleFacile.o userPlayDiff.o userPlayFac.o
	gcc main.o fonctionCommune.o grilleDifficile.o grilleFacile.o userPlayDiff.o userPlayFac.o -o jeu
