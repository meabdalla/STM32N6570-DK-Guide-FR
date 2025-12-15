/**
******************************************************************************
* @file    app_person_counter.c
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

/* Includes ------------------------------------------------------------------*/
#include "app_person_counter.h"
#include "stm32n6xx_hal.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define PERSON_CLASS_INDEX  0  /* Index de la classe "person" */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static PersonCounter_Status_t counter_status = {0};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief Initialise le compteur de personnes
 */
void PersonCounter_Init(void)
{
  memset(&counter_status, 0, sizeof(PersonCounter_Status_t));
  counter_status.last_update_time = HAL_GetTick();
}

/**
 * @brief Met à jour le compteur avec les résultats de détection
 * @param pp_output Pointeur vers les résultats du post-processing
 * @return Nombre de personnes détectées
 */
uint32_t PersonCounter_Update(od_pp_out_t *pp_output)
{
  if (pp_output == NULL)
  {
    return 0;
  }

  uint32_t person_count = 0;
  od_pp_outBuffer_t *rois = pp_output->pOutBuff;
  uint32_t nb_rois = pp_output->nb_detect;

  /* Compter le nombre de personnes détectées */
  for (uint32_t i = 0; i < nb_rois; i++)
  {
    if (rois[i].class_index == PERSON_CLASS_INDEX)
    {
      person_count++;
    }
  }

  /* Mise à jour du statut */
  counter_status.person_count = person_count;
  counter_status.total_objects = nb_rois;
  counter_status.last_update_time = HAL_GetTick();

  return person_count;
}

/**
 * @brief Obtient le statut actuel du compteur
 * @param status Pointeur vers la structure de statut à remplir
 */
void PersonCounter_GetStatus(PersonCounter_Status_t *status)
{
  if (status != NULL)
  {
    memcpy(status, &counter_status, sizeof(PersonCounter_Status_t));
  }
}

/**
 * @brief Obtient le nombre de personnes détectées
 * @return Nombre de personnes détectées
 */
uint32_t PersonCounter_GetCount(void)
{
  return counter_status.person_count;
}
