#ifndef __MQTT_CLIENT_INTERNAL_H__
#define __MQTT_CLIENT_INTERNAL_H__

#ifdef USE_LOGGING_FRAMEWORK

    #include "logging_config.h"

    #define LIBRARY_LOG_NAME             "MQTT"

    #ifdef MQTT_LOG_LEVEL
        #define LIBRARY_LOG_LEVEL        MQTT_LOG_LEVEL
    #else
        #ifdef IOT_LOG_LEVEL_GLOBAL
            #define LIBRARY_LOG_LEVEL    IOT_LOG_LEVEL_GLOBAL
        #else
            #define LIBRARY_LOG_LEVEL    IOT_LOG_NONE
        #endif
    #endif
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

#include "config.h"

#endif /* ifndef __MQTT_CLIENT_INTERNAL_H__ */
