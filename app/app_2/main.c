#include <stdio.h>
#include "shadow_client.h"

int main( void )
{
    printf( "Invoking Shadow Library...\nDebug Configuration:\nShadow --> Debug\nMQTT --> None\n\n" );
    Shadow_Get();

    return 0;
}
