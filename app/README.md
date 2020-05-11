## Build Information for App_1 and App_2
Each of the apps only calls the `Shadow_Get` function, but specifies configuration for both MQTT and Shadow libraries.

Build Directory for the below commands is the root directory of the branch (i.e. ../).

### App_1 
<b>Logging level Configuration:</b>
* Debug for MQTT
* Warning for Shadow

`gcc -std=gnu99 -I app/app_1 -I app/logging-framework -I app/logging-stack -I app/mqtt -I app/shadow app/app_1/main.c app/logging-stack/clock_posix.c app/logging-stack/logging.c app/mqtt/mqtt_client.c app/shadow/shadow_client.c -o app_1`

### App_2
<b>Logging level Configuration:</b>
* None for MQTT
* Debug for Shadow

`gcc -std=gnu99 -I app/app_2 -I app/logging-framework -I app/logging-stack -I app/mqtt -I app/shadow app/app_2/main.c app/logging-stack/clock_posix.c app/logging-stack/logging.c app/mqtt/mqtt_client.c app/shadow/shadow_client.c -o app_2`