#ifndef __MQTT_CONFIG_H__
#define __MQTT_CONFIG_H__

#include "config.h"
#include "logging_levels.h"

#define LIBRARY_LOG_NAME     "MQTT"

#define LIBRARY_LOG_LEVEL    LOG_DEBUG

#ifndef LogError
    #define LogError( message )
#endif

#ifndef LogErrorWithArgs
    #define LogErrorWithArgs( formatAndStrings )
#endif

#ifndef LogWarn
    #define LogWarn( message )
#endif

#ifndef LogWarnWithArgs
    #define LogWarnWithArgs( formatAndStrings )
#endif

#ifndef LogInfo
    #define LogInfo( message )
#endif

#ifndef LogInfoWithArgs
    #define LogInfoWithArgs( formatAndStrings )
#endif

#ifndef LogDebug
    #define LogDebug( message )
#endif

#ifndef LogDebugWithArgs
    #define LogDebugWithArgs( formatAndStrings )
#endif



#endif /* ifndef __MQTT_CONFIG_H__ */
