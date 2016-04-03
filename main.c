#include "inclusions.h"

int main( int argc, char *args[ ] )
{
    if ( Initialiser( ) == -1 ) /* Initialisation SDL */
        return EXIT_FAILURE;
    if ( Ouvrir_Fenetre( "al cheikh mat" ) == -1 ) /* Ouvrir la fenetre */
        return EXIT_FAILURE;

    gestionEvenement( );

    Finaliser( ); /* Fermer la SDL */

    return EXIT_SUCCESS;
}
