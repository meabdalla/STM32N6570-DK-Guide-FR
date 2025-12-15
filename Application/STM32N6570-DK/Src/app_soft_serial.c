/**
 ******************************************************************************
 * @file    app_soft_serial.c
 * @author  Antigravity
 * @brief   Implementation of Software Serial (Bit-Banging)
 ******************************************************************************
 */

#include "app_soft_serial.h"

/* Timing pour 9600 bauds : 1 bit = 104.16 us */
#define BIT_DELAY_US    104

/* Macros pour GPIO */
#define TX_HIGH()       HAL_GPIO_WritePin(SS_TX_PORT, SS_TX_PIN, GPIO_PIN_SET)
#define TX_LOW()        HAL_GPIO_WritePin(SS_TX_PORT, SS_TX_PIN, GPIO_PIN_RESET)
#define RX_READ()       HAL_GPIO_ReadPin(SS_RX_PORT, SS_RX_PIN)

/* Délai bloquant en microsecondes utilisant DWT */
/* Note: SystemCoreClock est 800MHz. DWT cyccnt incrémente à cette vitesse. */
static void Delay_Us(uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t cycles = us * (SystemCoreClock / 1000000);
    
    while ((DWT->CYCCNT - start) < cycles);
}

void SoftSerial_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable Clocks */
    SS_RX_CLK_EN();
    SS_TX_CLK_EN();
    
    /* Enable DWT for timing */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    /* Configure TX (PG2 / D11) */
    GPIO_InitStruct.Pin = SS_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(SS_TX_PORT, &GPIO_InitStruct);
    
    /* Idle State High */
    TX_HIGH();

    /* Configure RX (PA3 / D10) */
    GPIO_InitStruct.Pin = SS_RX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(SS_RX_PORT, &GPIO_InitStruct);
}

void SoftSerial_WriteByte(uint8_t byte)
{
    /* Start Bit (Low) */
    TX_LOW();
    Delay_Us(BIT_DELAY_US);
    
    /* Data Bits (LSB first) */
    for (int i = 0; i < 8; i++)
    {
        if (byte & 1) TX_HIGH();
        else          TX_LOW();
        
        Delay_Us(BIT_DELAY_US);
        byte >>= 1;
    }
    
    /* Stop Bit (High) */
    TX_HIGH();
    Delay_Us(BIT_DELAY_US);
}

void SoftSerial_Print(const char* str)
{
    while (*str)
    {
        SoftSerial_WriteByte((uint8_t)*str++);
    }
}

void SoftSerial_Write(const uint8_t* data, uint16_t len)
{
    for (uint16_t i = 0; i < len; i++)
    {
        SoftSerial_WriteByte(data[i]);
    }
}

/* Lecture bloquante d'un octet avec timeout */
/* Retourne -1 si timeout ou erreur */
int SoftSerial_Read(void)
{
    /* Attendre le Start Bit (Falling Edge) */
    uint32_t timeout = 10000000; /* ~10M loops = ~60ms timeout @ 800MHz */
    while (RX_READ() == GPIO_PIN_SET)
    {
        if (--timeout == 0) return -1;
    }
    
    /* Start bit détecté. Attendre 1.5 bit pour échantillonner au milieu du bit 0 */
    Delay_Us(BIT_DELAY_US + (BIT_DELAY_US / 2));
    
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        if (RX_READ() == GPIO_PIN_SET)
        {
            byte |= (1 << i);
        }
        Delay_Us(BIT_DELAY_US);
    }
    
    /* Attendre le Stop Bit (optionnel, pour synchro) */
    // Delay_Us(BIT_DELAY_US / 2);
    
    return byte;
}

/* Vérifie si une ligne est basse (Start bit potentiel) */
int SoftSerial_Available(void)
{
    return (RX_READ() == GPIO_PIN_RESET);
}
