#include <stdio.h>
#include "mqtt_client.h"
#include "shadow_client.h"

int main( void )
{
    printf( "Calling MQTT_PublishMessage...\n" );
    MQTT_PublishMessage();

    printf( "Calling Shadow_Get...\n" );
    Shadow_Get();

    return 0;
}
