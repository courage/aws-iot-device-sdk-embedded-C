#include "shadow_client.h"
#include "shadow_client_internal.h"

void Shadow_Get( void )
{
    LogError( "Error log string.\n" );
    LogErrorWithArgs( "Error log with one arg: %d.\n", 1 );
    LogWarn( "Warning log string.\n" );
    LogWarnWithArgs( "Warning log with one arg: %d.\n", 1 );
    LogInfo( "Info log string.\n" );
    LogInfoWithArgs( "Info log with one arg: %d.\n", 1 );
    LogDebug( "Debug log string.\n" );
    LogDebugWithArgs( "Debug log with one arg: %d.\n", 1 );
}
