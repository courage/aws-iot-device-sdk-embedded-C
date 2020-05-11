/*
 * Common Logging Framework
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file logging_setup.h
 * @brief Defines the common logging framework that calls #Log interface.
 */

#ifndef LOGGING_SETUP_H_
#define LOGGING_SETUP_H_

/* The config header is always included first. */
#include "config.h"

/* Include header for logging level macros. */
#include "logging_levels.h"

/* Check that LIBRARY_LOG_LEVEL is defined and has a valid value. */
#if !defined( LIBRARY_LOG_LEVEL ) ||           \
    ( ( LIBRARY_LOG_LEVEL != LOG_NONE ) && \
    ( LIBRARY_LOG_LEVEL != LOG_ERROR ) &&  \
    ( LIBRARY_LOG_LEVEL != LOG_WARN ) &&   \
    ( LIBRARY_LOG_LEVEL != LOG_INFO ) &&   \
    ( LIBRARY_LOG_LEVEL != LOG_DEBUG ) )
    #error "Please define LIBRARY_LOG_LEVEL as either LOG_NONE, LOG_ERROR, LOG_WARN, LOG_INFO, or LOG_DEBUG."
#else
    #if LIBRARY_LOG_LEVEL != LOG_NONE
        #if !defined( Log )
            #error "Please define the common logging interface macro, Log(messageLevel, pFormat, ...)."
        #endif
    #endif

    #if LIBRARY_LOG_LEVEL == LOG_DEBUG
        /* All log level messages will logged. */
        #define LogError( message )                 Log( LOG_ERROR, "%s", message )
        #define LogErrorWithArgs( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
        #define LogWarn( message )                  Log( LOG_WARN, "%s", message )
        #define LogWarnWithArgs( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
        #define LogInfo( message )                  Log( LOG_INFO, "%s", message )
        #define LogInfoWithArgs( pFormat, ... )     Log( LOG_INFO, pFormat, __VA_ARGS__ )
        #define LogDebug( message )                 Log( LOG_DEBUG, "%s", message )
        #define LogDebugWithArgs( pFormat, ... )    Log( LOG_DEBUG, pFormat, __VA_ARGS__ )

    #elif LIBRARY_LOG_LEVEL == LOG_INFO
        /* Only INFO, WARNING and ERROR messages will be logged. */
        #define LogError( message )                 Log( LOG_ERROR, "%s", message )
        #define LogErrorWithArgs( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
        #define LogWarn( message )                  Log( LOG_WARN, "%s", message )
        #define LogWarnWithArgs( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
        #define LogInfo( message )                  Log( LOG_INFO, "%s", message )
        #define LogInfoWithArgs( pFormat, ... )     Log( LOG_INFO, pFormat, __VA_ARGS__ )
        #define LogDebug( message )
        #define LogDebugWithArgs( pFormat, ... )

    #elif LIBRARY_LOG_LEVEL == LOG_WARN
        /* Only WARNING and ERROR messages will be logged.*/
        #define LogError( message )                 Log( LOG_ERROR, "%s", message )
        #define LogErrorWithArgs( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
        #define LogWarn( message )                  Log( LOG_WARN, "%s", message )
        #define LogWarnWithArgs( pFormat, ... )     Log( LOG_WARN, pFormat, __VA_ARGS__ )
        #define LogInfo( message )
        #define LogInfoWithArgs( pFormat, ... )
        #define LogDebug( message )
        #define LogDebugWithArgs( pFormat, ... )

    #elif LIBRARY_LOG_LEVEL == LOG_ERROR
        /* Only ERROR messages will be logged. */
        #define LogError( message )                 Log( LOG_ERROR, "%s", message )
        #define LogErrorWithArgs( pFormat, ... )    Log( LOG_ERROR, pFormat, __VA_ARGS__ )
        #define LogWarn( message )
        #define LogWarnWithArgs( pFormat, ... )
        #define LogInfo( message )
        #define LogInfoWithArgs( pFormat, ... )
        #define LogDebug( message )
        #define LogDebugWithArgs( pFormat, ... )

    #else /* if LIBRARY_LOG_LEVEL == LOG_ERROR */
        #define LogError( message )
        #define LogErrorWithArgs( pFormat, ... )
        #define LogWarn( message )
        #define LogWarnWithArgs( pFormat, ... )
        #define LogInfo( message )
        #define LogInfoWithArgs( pFormat, ... )
        #define LogDebug( message )
        #define LogDebugWithArgs( pFormat, ... )
    #endif /* if LIBRARY_LOG_LEVEL == LOG_ERROR */
#endif /* if !defined( LIBRARY_LOG_LEVEL ) || ( ( LIBRARY_LOG_LEVEL != LOG_NONE ) && ( LIBRARY_LOG_LEVEL != LOG_ERROR ) && ( LIBRARY_LOG_LEVEL != LOG_WARN ) && ( LIBRARY_LOG_LEVEL != LOG_INFO ) && ( LIBRARY_LOG_LEVEL != LOG_DEBUG ) ) */

#endif /* ifndef LOGGING_SETUP_H_ */
