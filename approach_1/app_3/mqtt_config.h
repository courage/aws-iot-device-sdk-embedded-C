#ifndef __MQTT_CONFIG_H__
#define __MQTT_CONFIG_H__

#include "logging.h"
#include "logging_levels.h"

#define LIBRARY_LOG_LEVEL    LOG_DEBUG

#define Log( messageLevel, pFormat, ... ) \
    Log_Generic( messageLevel,            \
                 "[%s:%d] [%s] "pFormat,  \
                 __FILE__,                \
                 __LINE__,                \
                 "MQTT",                  \
                 __VA_ARGS__ )

#define LogError( message )                     LogErrorC99 message
#define LogErrorWithArgs( formatAndStrings )    LogErrorWithArgsC99 formatAndStrings
#define LogWarn( message )                      LogWarnC99 message
#define LogWarnWithArgs( formatAndStrings )     LogWarnWithArgsC99 formatAndStrings
#define LogInfo( message )                      LogInfoC99 message
#define LogInfoWithArgs( formatAndStrings )     LogInfoWithArgsC99 formatAndStrings
#define LogDebug( message )                     LogDebugC99 message
#define LogDebugWithArgs( formatAndStrings )    LogDebugWithArgsC99 formatAndStrings



#if LIBRARY_LOG_LEVEL == LOG_DEBUG
    /* All log level messages will logged. */
    #define LogErrorC99( message )                 Log( LOG_ERROR, "%s", message )
    #define LogErrorWithArgsC99( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
    #define LogWarnC99( message )                  Log( LOG_WARN, "%s", message )
    #define LogWarnWithArgsC99( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
    #define LogInfoC99( message )                  Log( LOG_INFO, "%s", message )
    #define LogInfoWithArgsC99( pFormat, ... )     Log( LOG_INFO, pFormat, __VA_ARGS__ )
    #define LogDebugC99( message )                 Log( LOG_DEBUG, "%s", message )
    #define LogDebugWithArgsC99( pFormat, ... )    Log( LOG_DEBUG, pFormat, __VA_ARGS__ )

#elif LIBRARY_LOG_LEVEL == LOG_INFO
    /* Only INFO, WARNING and ERROR messages will be logged. */
    #define LogErrorC99( message )                 Log( LOG_ERROR, "%s", message )
    #define LogErrorWithArgsC99( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
    #define LogWarnC99( message )                  Log( LOG_WARN, "%s", message )
    #define LogWarnWithArgsC99( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
    #define LogInfoC99( message )                  Log( LOG_INFO, "%s", message )
    #define LogInfoWithArgsC99( pFormat, ... )     Log( LOG_INFO, pFormat, __VA_ARGS__ )
    #define LogDebugC99( message )
    #define LogDebugWithArgsC99( pFormat, ... )

#elif LIBRARY_LOG_LEVEL == LOG_WARN
    /* Only WARNING and ERROR messages will be logged.*/
    #define LogErrorC99( message )                 Log( LOG_ERROR, "%s", message )
    #define LogErrorWithArgsC99( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
    #define LogWarnC99( message )                  Log( LOG_WARN, "%s", message )
    #define LogWarnWithArgsC99( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
    #define LogInfoC99( message )
    #define LogInfoWithArgsC99( pFormat, ... )
    #define LogDebugC99( message )
    #define LogDebugWithArgsC99( pFormat, ... )

#elif LIBRARY_LOG_LEVEL == LOG_ERROR
    /* Only ERROR messages will be logged. */
    #define LogErrorC99( message )                 Log( LOG_ERROR, "%s", message )
    #define LogErrorWithArgsC99( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
    #define LogWarnC99( message )
    #define LogWarnWithArgsC99( pFormat, ... )
    #define LogInfoC99( message )
    #define LogInfoWithArgsC99( pFormat, ... )
    #define LogDebugC99( message )
    #define LogDebugWithArgsC99( pFormat, ... )

#else /* if LIBRARY_LOG_LEVEL == LOG_ERROR */
    #define LogErrorC99( message )
    #define LogErrorWithArgsC99( pFormat, ... )
    #define LogWarnC99( message )
    #define LogWarnWithArgsC99( pFormat, ... )
    #define LogInfoC99( message )
    #define LogInfoWithArgsC99( pFormat, ... )
    #define LogDebugC99( message )
    #define LogDebugWithArgsC99( pFormat, ... )
#endif /* if LIBRARY_LOG_LEVEL == LOG_DEBUG */

#endif /* ifndef __MQTT_CONFIG_H__ */
