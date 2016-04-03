#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include "inclusions.h"

/** Initialisation */
int Initialiser( void );
int Finaliser( void );
/** Affichage */
int Ouvrir_Fenetre( char* nomFenetre );
int Nettoyage( void );
static SDL_Surface *Charger_Image( char *nomFichier );
static void Appliquer_Surface( int x, int y, SDL_Surface *source, SDL_Surface *destination );
/** Evenement */
void gestionEvenement( void );

#endif // PROTOTYPES_H_INCLUDED
