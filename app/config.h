/*
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

#ifndef CONFIG_H
#define CONFIG_H

/* Include file for POSIX reference implementation. */
#include "platform/include/iot_logging.h"

/* Check if compiler supports C99 or above, as variadic macros are supported in the C99 standard. */
#if defined( __STDC_VERSION__ ) && __STDC_VERSION__ >= 199901L

/* Define the IotLog logging interface to enabling logging.
 * This demo maps the macro to the reference POSIX implementation for logging.
 * Note: @ref LIBRARY_LOG_NAME adds the name of the library, that produces the
 * log, as metadata in each log message. */
    #define IotLog( messageLevel, pFormat, ... ) \
    IotLog_Generic( messageLevel,                \
                    "[%s:%d] [%s] "pFormat,      \
                    __FILE__,                    \
                    __LINE__,                    \
                    LIBRARY_LOG_NAME,            \
                    __VA_ARGS__ )

    #include "iot_logging_setup.h"

#else /* if __STDC_VERSION__ >= 199901L */

    #define IotLogErrorC90( formatStringAndArgs )    IotLog_Error formatStringAndArgs
    #define IotLogWarnC90( formatStringAndArgs )     IotLog_Warn formatStringAndArgs
    #define IotLogInfoC90( formatStringAndArgs )     IotLog_Info formatStringAndArgs
    #define IotLogDebugC90( formatStringAndArgs )    IotLog_Debug formatStringAndArgs

#endif /* if __STDC_VERSION__ >= 199901L */


#endif /* ifndef CONFIG_H */
