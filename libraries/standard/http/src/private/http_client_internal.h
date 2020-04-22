#ifndef __HTTP_CLIENT_INTERNAL_H__
#define __HTTP_CLIENT_INTERNAL_H__

#include "config.h"

#ifdef HTTP_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL        MQTT_LOG_LEVEL
#else
    #ifdef IOT_LOG_LEVEL_GLOBAL
        #define LIBRARY_LOG_LEVEL    IOT_LOG_LEVEL_GLOBAL
    #else
        #define LIBRARY_LOG_LEVEL    IOT_LOG_NONE
    #endif
#endif

#endif /* ifndef __HTTP_CLIENT_INTERNAL_H__ */
