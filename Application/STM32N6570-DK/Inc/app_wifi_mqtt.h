/**
 * @file    app_wifi_mqtt.h
 * @author  Antigravity
 * @brief   Header file for WiFi and MQTT application
 */

#ifndef APP_WIFI_MQTT_H
#define APP_WIFI_MQTT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32n6xx_hal.h"

/* Fonctions Publiques */
void WiFi_Init(void);
void WiFi_Process(void);
void MQTT_Publish_PersonCount(uint32_t count);
uint8_t WiFi_IsConnected(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_WIFI_MQTT_H */
