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
enum demEvents
{
  EXAMPLE_EVENT_1,
  EXAMPLE_EVENT_2,
  EXAMPLE_EVENT_3,
  EXAMPLE_EVENT_4,
  NUMBER_OF_EVENTS
};


/*! \def MAX_NUMBER_OF_EVENTS
 *  \brief Max number of events
 *
 *  Defines the max number of events that the DEM can handle and is configured for.
 *  Max number of events that can be configured is 256.
 */
#define MAX_NUMBER_OF_EVENTS 100

/*! \def ERROR_MEMORY_SIZE
 *  \brief Size of the error memory
 *
 *  Defines the size of the error memory i.e. the number of errors that can be
 *  in total. If the error memory is full all new errors will be discarded.
 */
#define ERROR_MEMORY_SIZE 10

Dem_Event_Type errorMemory[ERROR_MEMORY_SIZE];

Dem_Event_Type eventList[MAX_NUMBER_OF_EVENTS] = {
    {
        .eventID = EXAMPLE_EVENT_1,
        .debounceCounter = 10,
        .failedLvl = 127,
        .passedLvl = -128,
        .statusBits = INIT_BIT
    },
    {
        .eventID = EXAMPLE_EVENT_2,
        .debounceCounter = 10,
        .failedLvl = 127,
        .passedLvl = -128,
        .statusBits = INIT_BIT
    },
    {
        .eventID = EXAMPLE_EVENT_3,
        .debounceCounter = 20,
        .failedLvl = 127,
        .passedLvl = -128,
        .statusBits = INIT_BIT
    },
    {
        .eventID = EXAMPLE_EVENT_4,
        .debounceCounter = 30,
        .failedLvl = 127,
        .passedLvl = -128,
        .statusBits = INIT_BIT
    }
};

#endif /* SRC_DEM_INC_DEM_CONFIG_H_ */
