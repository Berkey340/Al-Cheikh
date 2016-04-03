#include "inclusions.h"

int Initialiser( void ) {

/** -Ne reçoit rien
    -Renvoie -1 si une erreur advient 0 si tout ce passe bien
    -Initialise les systemes/sous-systemes sdl (Video, audio, ttf...) */

freopen("CON", "w", stdout); /* Permet d'ouvrir un flux vers la console */

if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) { /* Si l'initialisation rate, on ecrit dans le fichier stderr */
    fprintf( stderr, "Erreur initialisation SDL : %s\n", SDL_GetError( ) );
    return -1;
}
printf("La SDL c'est bien initialiser.\n");

atexit( SDL_Quit ); /* Sur une fermeture inopinee on ferme les sous-systemes */

return 0;}

/*--------------------------------------------------------------------------*/

int Finaliser( void ) {

/** -Ne reçoit rien
    -Renvoie -1 si une erreur advient 0 si tout ce passe bien
    -Referme les systemes sdl                                 */

Nettoyage( ); /* Nettoyage des surfaces */
printf("Tout a ete nettoye.\n");
SDL_Quit( ); /* Fermeture des sous-systemes */
printf("La SDL a ete fermee.\n");

return 0;}
