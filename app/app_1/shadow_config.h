#ifndef __SHADOW_CONFIG_H__
#define __SHADOW_CONFIG_H__

#include "logging_levels.h"
#include "c99_logging_setup.h"

#define LIBRARY_LOG_NAME    "Shadow"

#define LogError( message )                     Log( LIBRARY_LOG_NAME, LOG_ERROR, message )
#define LogErrorWithArgs( formatAndStrings )    LogWithArgs( LIBRARY_LOG_NAME, LOG_ERROR, formatAndStrings )
#define LogWarn( message )                      Log( LIBRARY_LOG_NAME, LOG_WARN, message )
#define LogWarnWithArgs( formatAndStrings )     LogWithArgs( LIBRARY_LOG_NAME, LOG_WARN, formatAndStrings )
#define LogInfo( message )
#define LogInfoWithArgs( formatAndStrings )
#define LogDebug( message )
#define LogDebugWithArgs( formatAndStrings )


#endif /* ifndef __SHADOW_CONFIG_H__ */
