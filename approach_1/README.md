## Build Information for App_1 and App_2
Each of the apps only calls the `MQTT_PublishMessage` and `Shadow_Get` function, and specifies configuration for both MQTT and Shadow libraries.

### App_1 
<b>Logging level Configuration:</b>
* Debug for MQTT
* Warning for Shadow

`gcc -std=gnu99 -I app_1 -I logging-framework -I logging-stack -I mqtt -I mqtt/private -I shadow -I shadow/private app_1/main.c logging-stack/clock_posix.c logging-stack/logging.c mqtt/mqtt_client.c shadow/shadow_client.c -o build_1`

### App_2
<b>Logging level Configuration:</b>
* None for MQTT
* None for Shadow

`gcc -std=gnu99 -I app_2 -I logging-framework -I logging-stack -I mqtt -I mqtt/private -I shadow -I shadow/private app_2/main.c logging-stack/clock_posix.c logging-stack/logging.c mqtt/mqtt_client.c shadow/shadow_client.c -o build_2`