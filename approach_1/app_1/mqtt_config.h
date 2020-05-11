#ifndef __MQTT_CONFIG_H__
#define __MQTT_CONFIG_H__

#include "c99_logging_setup.h"

#define LIBRARY_LOG_NAME    "MQTT"

#define LogError( message )                     Log( LIBRARY_LOG_NAME, LOG_ERROR, message )
#define LogErrorWithArgs( formatAndStrings )    LogWithArgs( LIBRARY_LOG_NAME, LOG_ERROR, formatAndStrings )
#define LogWarn( message )                      Log( LIBRARY_LOG_NAME, LOG_WARN, message )
#define LogWarnWithArgs( formatAndStrings )     LogWithArgs( LIBRARY_LOG_NAME, LOG_WARN, formatAndStrings )
#define LogInfo( message )                      Log( LIBRARY_LOG_NAME, LOG_INFO, message )
#define LogInfoWithArgs( formatAndStrings )     LogWithArgs( LIBRARY_LOG_NAME, LOG_INFO, formatAndStrings )
#define LogDebug( message )                     Log( LIBRARY_LOG_NAME, LOG_DEBUG, message )
#define LogDebugWithArgs( formatAndStrings )    LogWithArgs( LIBRARY_LOG_NAME, LOG_DEBUG, formatAndStrings )


#endif /* ifndef __MQTT_CONFIG_H__ */
