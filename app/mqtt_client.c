#include "mqtt_client.h"
#include "mqtt_config.h"

void MQTT_PublishMessage( void )
{
    IotLogError( ( "Error log string.\n" ) );
    IotLogErrorWithArgs( ( "Error log with one arg: %d.\n", 1 ) );
    IotLogWarn( ( "Warning log string.\n" ) );
    IotLogWarnWithArgs( ( "Warning log with one arg: %d.\n", 1 ) );
    IotLogInfo( ( "Info log string.\n" ) );
    IotLogInfoWithArgs( ( "Info log with one arg: %d.\n", 1 ) );
    IotLogDebug( ( "Debug log string.\n" ) );
    IotLogDebugWithArgs( ( "Debug log with one arg: %d.\n", 1 ) );
}
