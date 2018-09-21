/*
 * Dem_Types.h
 *
 *  Created on: 20 Sep 2018
 *      Author: Nagelfar
 */

#ifndef SRC_DEM_INC_DEM_TYPES_H_
#define SRC_DEM_INC_DEM_TYPES_H_

#include "Std_Types.h"

typedef uint16 eventID_Type;

enum status
{
  PRE_FAILED,
  PRE_PASSED,
  FAILED,
  PASSED
};

typedef struct
{
  eventID_Type DTC;
  uint16 debounceCounter;
  uint16 failedLvl;
  uint16 passedLvl;
} Dem_eventType;

#endif /* SRC_DEM_INC_DEM_TYPES_H_ */
