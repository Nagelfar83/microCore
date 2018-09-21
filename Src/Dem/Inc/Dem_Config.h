/*
 * Dem_Config.h
 *
 *  Created on: 18 Sep 2018
 *      Author: Nagelfar
 */

#ifndef SRC_DEM_INC_DEM_CONFIG_H_
#define SRC_DEM_INC_DEM_CONFIG_H_

#include "Dem.h"

/* TYPEDEFs AND OTHER DECLARATIONS */
typedef enum
{
  EXAMPLE_EVENT_1,
  EXAMPLE_EVENT_2,
  NUMBER_OF_EVENTS
} Dem_eventID;

/* GLOBAL DEFINES */
#define MAX_NUMBER_OF_EVENTS 10 /* Make it into a macro that calculates the size and if it is too big gives a warning */


Dem_eventType eventList[MAX_NUMBER_OF_EVENTS] = {
    {
        .DTC = 0xFFFF,
        .debounceCounter = 0x10,
        .failedLvl = 128,
        .passedLvl = 256
    },
    {
        .DTC = 0xFFEE,
        .debounceCounter = 0x10,
        .failedLvl = 128,
        .passedLvl = 256
    }
};


#endif /* SRC_DEM_INC_DEM_CONFIG_H_ */
