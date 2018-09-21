/*
 * Dem.c
 *
 *  Created on: 17 Sep 2018
 *      Author: Nagelfar
 */

#include "Dem_Config.h"
#include "Dem.h"

Std_ReturnType __findEvent(uint16 eventID, Dem_eventType *event);

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

Std_ReturnType __findEvent(uint16 eventID, Dem_eventType *event)
{
  uint16 Idx = 0;
  Std_ReturnType retVal = E_NOT_OK;
  Dem_eventType currentEvent = 0;

  while(eventID != eventList[Idx].eventID)
  {
    if(eventID == eventList[Idx])
    {
      *event = eventList[Idx];
      retVal = E_OK;
    }
    else
    {
      *event = NULL;
    }
  }

  return retVal;
}



