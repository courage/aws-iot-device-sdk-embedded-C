#include <stdio.h>
#include "shadow_client.h"

int main( void )
{
    printf( "Invoking Shadow Library...\nDebug Configuration:\nShadow --> Warning\nMQTT --> Debug\n\n" );
    Shadow_Get();

    return 0;
}
