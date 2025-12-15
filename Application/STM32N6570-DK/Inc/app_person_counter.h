/**
******************************************************************************
* @file    app_person_counter.h
* @author  GPM Application Team
*
******************************************************************************
* @attention
*
* Copyright (c) 2023 STMicroelectronics.
* All rights reserved.
*
* This software is licensed under terms that can be found in the LICENSE file
* in the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
******************************************************************************
*/

#ifndef APP_PERSON_COUNTER_H
#define APP_PERSON_COUNTER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "app_postprocess.h"

/* Exported types ------------------------------------------------------------*/
typedef struct {
  uint32_t person_count;       /* Nombre de personnes détectées */
  uint32_t total_objects;      /* Nombre total d'objets détectés */
  uint32_t last_update_time;   /* Timestamp de la dernière mise à jour */
} PersonCounter_Status_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/**
 * @brief Initialise le compteur de personnes
 */
void PersonCounter_Init(void);

/**
 * @brief Met à jour le compteur avec les résultats de détection
 * @param pp_output Pointeur vers les résultats du post-processing
 * @return Nombre de personnes détectées
 */
uint32_t PersonCounter_Update(od_pp_out_t *pp_output);

/**
 * @brief Obtient le statut actuel du compteur
 * @param status Pointeur vers la structure de statut à remplir
 */
void PersonCounter_GetStatus(PersonCounter_Status_t *status);

/**
 * @brief Obtient le nombre de personnes détectées
 * @return Nombre de personnes détectées
 */
uint32_t PersonCounter_GetCount(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_PERSON_COUNTER_H */
