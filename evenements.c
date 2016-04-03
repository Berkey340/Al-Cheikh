#include "inclusions.h"

enCours = 1;
SDL_Event evenement;

void gestionEvenement( void ) {
/** -Ne reçoit rien
    -Ne renvoit rien
    -Gere les evenement (principaux?) */

while( enCours == 1) {
    while ( SDL_PollEvent( &evenement ) ) {
    switch ( evenement.type ) {
    case SDL_QUIT:
        enCours = 0;
        printf( "La fenetre est ferme.\n" );
        break;
    default:
        break;
    }}
}
return 0;}
