/**
 * @file    app_wifi_mqtt.c
 * @author  Antigravity
 * @brief   Simple Serial Communication with ESP8266 Gateway
 */

#include "app_wifi_mqtt.h"
#include "app_soft_serial.h"
#include "stm32_lcd_ex.h"
#include "stm32_lcd.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* Private variables */
static uint8_t wifi_connected = 1; /* Assumed managed by ESP8266 */

/* Helper pour afficher sur LCD et Série */
static void Log_Status(const char* fmt, ...)
{
    char buf[64];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    
    printf("%s\r\n", buf);
    
    /* Affichage en bas de l'écran */
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_YELLOW);
    UTIL_LCDEx_PrintfAt(0, 440, CENTER_MODE, "                    "); /* Clear line */
    UTIL_LCDEx_PrintfAt(0, 440, CENTER_MODE, "%s", buf);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
}

/**
 * @brief Initialise le module de communication
 */
void WiFi_Init(void)
{
    /* Init Software Serial (D10/D11) @ 9600 baud */
    SoftSerial_Init();

    /* Délai pour laisser le module ESP8266 démarrer */
    HAL_Delay(2000);

    Log_Status("ESP Link Ready");
}

/**
 * @brief Envoie le nombre de personnes à l'ESP8266
 * Protocole: "COUNT:<n>\n"
 */
void MQTT_Publish_PersonCount(uint32_t count)
{
    static uint32_t last_published_count = 0xFFFFFFFF;
    static uint32_t last_publish_time = 0;
    const uint32_t HEARTBEAT_DELAY = 10000; /* 10 secondes heartbeat */

    /* Publier si le compte a changé OU si le délai heartbeat est dépassé */
    if (count != last_published_count || (HAL_GetTick() - last_publish_time > HEARTBEAT_DELAY))
    {
        char msg[32];
        /* Format simple que l'ESP8266 va parser */
        snprintf(msg, sizeof(msg), "COUNT:%lu\n", count);
        
        /* Envoi via Software Serial */
        SoftSerial_Print(msg);
        
        Log_Status("Sent: %lu", count);
        
        last_published_count = count;
        last_publish_time = HAL_GetTick();
    }
}

void WiFi_Process(void)
{
    /* Pas de traitement complexe nécessaire côté STM32 */
}

uint8_t WiFi_IsConnected(void)
{
    return wifi_connected;
}
