/*
 * Dem.c
 *
 *  Created on: 17 Sep 2018
 *      Author: Nagelfar
 */

#include "Dem_Config.h";
#include "Dem.h"

Std_ReturnType __findEvent();

int dem_main(void)
{
  return E_OK;
}

Std_ReturnType Dem_SetEventStatus(uint8_t Status)
{
  Std_ReturnType retVal = 0;

  retVal = __findEvent();

  return E_OK;
}

Std_ReturnType Dem_GetEventStatus()
{
  return E_OK;
}

Std_ReturnType Dem_ClearErrorMemor()
{
  return E_OK;
}

Std_ReturnType __findEvent(uint16 eventID)
{
  uint16 eventIDPos = 0;

  while()
  return E_OK;
}
