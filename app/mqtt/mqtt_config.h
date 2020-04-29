#ifndef __MQTT_CLIENT_INTERNAL_H__
#define __MQTT_CLIENT_INTERNAL_H__

#define LIBRARY_LOG_NAME     "MQTT"

#define LIBRARY_LOG_LEVEL    IOT_LOG_DEBUG

#ifndef IotLogError
    #define IotLogError( message )
#endif

#ifndef IotLogErrorWithArgs
    #define IotLogErrorWithArgs( formatAndStrings )
#endif

#ifndef IotLogWarn
    #define IotLogWarn( message )
#endif

#ifndef IotLogWarnWithArgs
    #define IotLogWarnWithArgs( formatAndStrings )
#endif

#ifndef IotLogInfo
    #define IotLogInfo( message )
#endif

#ifndef IotLogInfoWithArgs
    #define IotLogInfoWithArgs( formatAndStrings )
#endif

#ifndef IotLogDebug
    #define IotLogDebug( message )
#endif

#ifndef IotLogDebugWithArgs
    #define IotLogDebugWithArgs( formatAndStrings )
#endif


#endif /* ifdef USE_LOGGING_FRAMEWORK */
