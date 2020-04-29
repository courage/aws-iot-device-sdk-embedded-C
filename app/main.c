#include <stdio.h>
#include "config.h"
#include "mqtt_client.h"

int main( void )
{
    printf( "Invoking MQTT Library...\n\n" );
    MQTT_PublishMessage();

    return 0;
}
