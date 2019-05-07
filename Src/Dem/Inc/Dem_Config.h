/*! \file Dem_Config.h
 *  \brief Configuration file of the DEM
 *
 *  This file contains the configuration parameters for the DEM.
 *  Use this file to configure the behaviour of the DEM. Parameters that
 *  can be configured are for instance the size of the error memory, the
 *  different events and their properties etc. For a more detailed desciption
 *  of the functionality of the configuration file see section XX
 *
 *  TODO: Add ref. to section.
 */

#ifndef SRC_DEM_INC_DEM_CONFIG_H_
#define SRC_DEM_INC_DEM_CONFIG_H_

#include "Dem_Types.h"

/* TYPEDEFs AND OTHER DECLARATIONS */
/*! \enum Dem_eventID
 *
 *  \brief The list of DEM events
 *
 *  The last entry of the enum gives the number of events in the list.
 */
typedef enum
{
  EXAMPLE_EVENT_1,
  EXAMPLE_EVENT_2,
  NUMBER_OF_EVENTS
} Dem_eventID;


/*! \def MAX_NUMBER_OF_EVENTS
 *  \brief Max number of events
 *
 *  Defines the max number of events that the DEM can handle and is configured for.
 *  Max number of events that can be configured is 256.
 */
#define MAX_NUMBER_OF_EVENTS 10


Dem_eventType eventList[MAX_NUMBER_OF_EVENTS] = {
    {
        .eventID = 0xFFFF,
        .debounceCounter = 0x10,
        .failedLvl = 128,
        .passedLvl = 256
    },
    {
        .eventID = 0xFFEE,
        .debounceCounter = 0x10,
        .failedLvl = 128,
        .passedLvl = 256
    }
};

#endif /* SRC_DEM_INC_DEM_CONFIG_H_ */
