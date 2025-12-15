/**
 ******************************************************************************
 * @file    app_soft_serial.h
 * @author  Antigravity
 * @brief   Header for Software Serial (Bit-Banging) Driver
 ******************************************************************************
 */

#ifndef APP_SOFT_SERIAL_H
#define APP_SOFT_SERIAL_H

#include "stm32n6xx_hal.h"

/* Configuration des broches (D10=PA3=RX, D11=PG2=TX pour l'Arduino, donc l'inverse pour le STM32) */
/* ATTENTION: SoftwareSerial Arduino: RX, TX. 
   Si Arduino code = SoftwareSerial(10, 11) -> Pin 10 est RX (du point de vue Arduino), Pin 11 est TX.
   Donc STM32 doit Transmettre sur 10 et Recevoir sur 11 ?
   NON. SoftwareSerial(rxPin, txPin).
   Si user dit "utilisait 10 et 11", et que c'est un shield:
   Le shield a son TX connecté au RX de l'Arduino (10) et son RX connecté au TX de l'Arduino (11).
   Donc STM32 doit:
   - Lire sur Pin 10 (PA3) -> C'est le TX du Shield.
   - Ecrire sur Pin 11 (PG2) -> C'est le RX du Shield.
   
   VERIFICATION:
   Arduino D10 = PA3.
   Arduino D11 = PG2.
*/

/* Décommenter cette ligne pour inverser RX et TX si ça ne marche pas */
/* #define SWAP_PINS */

#ifdef SWAP_PINS
    /* Configuration INVERSÉE : TX sur D10, RX sur D11 */
    #define SS_TX_PIN       GPIO_PIN_3  /* D10 - PA3 */
    #define SS_TX_PORT      GPIOA
    #define SS_TX_CLK_EN()  __HAL_RCC_GPIOA_CLK_ENABLE()

    #define SS_RX_PIN       GPIO_PIN_2  /* D11 - PG2 */
    #define SS_RX_PORT      GPIOG
    #define SS_RX_CLK_EN()  __HAL_RCC_GPIOG_CLK_ENABLE()
#else
    /* Configuration NORMALE : RX sur D10, TX sur D11 (Standard SoftwareSerial 10,11) */
    #define SS_RX_PIN       GPIO_PIN_3  /* D10 - PA3 */
    #define SS_RX_PORT      GPIOA
    #define SS_RX_CLK_EN()  __HAL_RCC_GPIOA_CLK_ENABLE()

    #define SS_TX_PIN       GPIO_PIN_2  /* D11 - PG2 */
    #define SS_TX_PORT      GPIOG
    #define SS_TX_CLK_EN()  __HAL_RCC_GPIOG_CLK_ENABLE()
#endif

#define SS_BAUDRATE     9600        /* Software Serial est lent, 9600 est recommandé */

void SoftSerial_Init(void);
void SoftSerial_WriteByte(uint8_t byte);
void SoftSerial_Print(const char* str);
void SoftSerial_Write(const uint8_t* data, uint16_t len);
int SoftSerial_Read(void);
int SoftSerial_Available(void);

#endif /* APP_SOFT_SERIAL_H */
