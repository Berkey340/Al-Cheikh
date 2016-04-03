#include "inclusions.h"

extern SDL_Surface *ecran = NULL;

int Ouvrir_Fenetre( char* nomFenetre ) {
/** -Reçoit le nom de la fenetre
    -Renvoie -1 si une erreur advient 0 si tout ce passe bien
    -Procede a toute les etapes pour ouvrir une fenetre fonctionnele */

SDL_WM_SetCaption( nomFenetre, NULL );


/* Parametrage de l'ecran */
putenv("SDL_VIDEO_WINDOW_POS=center"); /* Positioner la fenetre au centre de l'ecran */
ecran = SDL_SetVideoMode( LONGUEUR_ECRAN, LARGEUR_ECRAN, BPP_ECRAN, SDL_HWSURFACE );
if( ecran == NULL ) { /* Si le paremetrage de l'ecran rate, on ecrit dans le fichier stderr */
    fprintf( stderr, "Erreur parametrage ecran : %s\n", SDL_GetError( ) );
    return -1;
}
printf("L'ecran a ete parametre en %dx%d.\n", LONGUEUR_ECRAN, LARGEUR_ECRAN);
SDL_WM_SetIcon( IMG_Load( "img/ico_blanche.png" ), NULL ); /* Afficher icone fenetre */

/* Affichage de l'echiquier */
SDL_Surface *echiquier = NULL;
echiquier = Charger_Image( "img/plateau.bmp" );
Appliquer_Surface( (LONGUEUR_ECRAN - echiquier->w)/2, 0, echiquier, ecran );
if( SDL_Flip( ecran ) == -1) {
    fprintf( stderr, "Erreur actualisation ecran : %s\n", SDL_GetError( ) );
    return -1;
}
printf( "L'echiquier est affiche.\n" );

/* Afficher un pion */
SDL_Surface *pion = IMG_Load( "img/pieces/pion_blanc.png" );
if( pion )
Appliquer_Surface( (BORD_TERRAIN-(pion->w/2))+TAILLE_CASE*(8-1), (BORD_TERRAIN-(pion->h/2))+TAILLE_CASE*(8-1), pion, ecran );
if( SDL_Flip( ecran ) == -1) {
    fprintf( stderr, "Erreur actualisation ecran : %s\n", SDL_GetError( ) );
    return -1;
}

return 0;}

/*--------------------------------------------------------------------------*/

int Nettoyage( void ) {
/** -Ne reçoit rien
    -Ne renvoie rien
    -Nettoie toute les surfaces ou autres */

SDL_FreeSurface( ecran );

return 0;}

/*--------------------------------------------------------------------------*/

static SDL_Surface *Charger_Image( char *nomFichier ) {
    /** -Reçoit l'emplacement d'une image
        -Renvoie une surface
        -Optimise l'image pour qu'elle s'afiche dans le meme format que l'ecran */

SDL_Surface *imageChargee = NULL;
SDL_Surface *imageOptimisee = NULL;

imageChargee = SDL_LoadBMP( nomFichier );

if( imageChargee != NULL ) {
    imageOptimisee = SDL_DisplayFormat( imageChargee );
    SDL_FreeSurface( imageChargee );
}

return imageOptimisee;}

/*--------------------------------------------------------------------------*/

static void Appliquer_Surface( int x, int y, SDL_Surface *source, SDL_Surface *destination ) {
SDL_Rect offset;
offset.x = x;
offset.y = y;
SDL_BlitSurface( source, NULL, destination, &offset);
return 0;}
