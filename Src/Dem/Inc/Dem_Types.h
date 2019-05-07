/*! \file Dem_Types.h
 *  \brief Data types of the DEM
 *
 *  This header file contains the data types that are associated
 *  with the DEM module. It includes the standard types header for
 *  access to the standard type definitions.
 */

#ifndef SRC_DEM_INC_DEM_TYPES_H_
#define SRC_DEM_INC_DEM_TYPES_H_

#include "Std_Types.h"

typedef uint16 eventID_Type;

/*! \enum status
 *  \brief DEM event status
 *
 *  The different status that a DEM event can have.
 */
enum status
{
  PRE_FAILED, /*!< Indicates that an event has failed */
  PRE_PASSED, /*!< Indicates that an event has recovered*/
  FAILED,     /*!< Indicates that an event has reach its failed limit*/
  PASSED      /*!< Indicates that an event has reached its healing limit*/
};

/*! \struct Dem_eventType
 *  \brief DEM Event
 *
 *  This is the advanced data type of an DEM event.
 *  It contains several configuration properties that can be set for each event.
 */
typedef struct
{
  eventID_Type eventID;   /*!< The events unique ID*/
  uint16 debounceCounter; /*!< The debounce counter for the event*/
  uint16 failedLvl;       /*!< The configurable failed limit for the event*/
  uint16 passedLvl;       /*!< The configurable passed limit for the event*/
} Dem_eventType;

#endif /* SRC_DEM_INC_DEM_TYPES_H_ */
