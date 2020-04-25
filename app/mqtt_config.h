#ifndef __MQTT_CLIENT_INTERNAL_H__
#define __MQTT_CLIENT_INTERNAL_H__

#include "config.h"

#ifdef USE_LOGGING_FRAMEWORK

    #define LIBRARY_LOG_NAME     "MQTT"

    #define LIBRARY_LOG_LEVEL    IOT_LOG_DEBUG

/* Dependency on logging framework */
    #include "iot_logging_setup.h"
#else /* ifdef USE_LOGGING_FRAMEWORK */

    #define IotLogError( message )
    #define IotLogErrorWithArgs( formatAndStrings )
    #define IotLogWarn( message )
    #define IotLogWarnWithArgs( formatAndStrings )
    #define IotLogInfo( message )
    #define IotLogInfoWithArgs( formatAndStrings )
    #define IotLogDebug( message )
    #define IotLogDebugWithArgs( formatAndStrings )

#endif /* ifdef USE_LOGGING_FRAMEWORK */

#endif /* ifndef __MQTT_CLIENT_INTERNAL_H__ */
