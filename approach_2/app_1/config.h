#ifndef CONFIG_H__
#define CONFIG_H__

#include "logging.h"

/* Redirect logs to our logging function. */
#define Log( messageLevel, pFormat, ... ) \
    Log_Generic( "[%s:%d] [%s] "pFormat,  \
                __FILE__,                 \
                __LINE__,                 \
                 LIBRARY_LOG_NAME,        \
                 __VA_ARGS__ )

/* Log level for MQTT is debug - most verbose. */
#define MQTT_LOG_LEVEL      LOG_DEBUG

/* Log level for Shadow is warning. */
#define SHADOW_LOG_LEVEL    LOG_WARN

#endif /* ifndef CONFIG_H__ */
