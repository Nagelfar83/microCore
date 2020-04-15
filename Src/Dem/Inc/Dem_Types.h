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

//#define EMPTY 255
#define DEBOUNCE_INIT 0

typedef uint16 Dem_EventID_Type;
typedef sint16 Dem_DebounceCounter_Type;
typedef sint16 Dem_FailedPassedLvl_Type;

/*! \enum status
 *  \brief DEM event status
 *
 *  The different status that a DEM event can have.
 */
typedef enum demEventStatus
{
  PRE_FAILED, /*!< Indicates that an event has failed */
  PRE_PASSED, /*!< Indicates that an event has recovered*/
  FAILED,     /*!< Indicates that an event has reach its failed limit*/
  PASSED      /*!< Indicates that an event has reached its healing limit*/
} Dem_EventStatus_Type; //update code I added _Type

/*! \enum status bits
 *  \brief DEM event status bits
 *
 *  The different status bit that a event can have.
 */
typedef enum demStatusBits
{
  INIT_BIT = 0,
  PENDING_BIT = 1,
  PASSED_BIT = 2,
  FAILED_BIT = 4,
  CONFIRMED_BIT = 8
} Dem_StatusBits_Type;

/*! \struct Dem_eventType
 *  \brief DEM Event
 *
 *  This is the advanced data type of an DEM event.
 *  It contains several configuration properties that can be set for each event.
 */
typedef struct
{
  Dem_EventID_Type eventID;                   /*!< The events unique ID*/
  Dem_DebounceCounter_Type debounceCounter;   /*!< The debounce counter for the event*/
  Dem_FailedPassedLvl_Type failedLvl;         /*!< The configurable failed limit for the event*/
  Dem_FailedPassedLvl_Type passedLvl;         /*!< The configurable passed limit for the event*/
  Dem_StatusBits_Type statusBits;             /*!< The current status bits of the event */
} Dem_Event_Type;

#endif /* SRC_DEM_INC_DEM_TYPES_H_ */
