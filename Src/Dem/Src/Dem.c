/*! \file
 *
 *  \brief DEM (Diagnostic Event Manage).
 *
 *  The DEM processes all diagnostic events that are reported to it.
 *  It's basic functionality is to handle debouncing of events and error memory storage.
 *  For further information about how the DEM works and how to configure it see section XX.
 *
 *  TODO: Add reference to DEM section in.
 */

//#include "Dem_Config.h"
#include "Dem.h"
#include <math.h>

/* Local functions */
Std_Return_Type __findEvent(Dem_EventID_Type eventID, Dem_Event_Type *eventPtr);
Std_Return_Type __getNumberOfEvents(uint16 *numberOfEvents);
Std_Return_Type __addToErrorMemory(Dem_Event_Type *eventPtr);
Std_Return_Type __removeFromErrorMemory(Dem_Event_Type *eventPtr);

/*!  \brief DEM init function.
 *
 *  This is the DEM initialisation function that initialises the
 *  DEMs event data. It shall be run once at each startup.
 */
Std_Return_Type Dem_Init()
{
  uint16 idx = 0;
  uint16 numberOfEvents = 0;
  Std_Return_Type retVal = E_NOT_OK;

  __getNumberOfEvents(&numberOfEvents);

  /* Clear the event data counters */
  for(idx = 0 ; idx < numberOfEvents ; idx++)
  {
    eventList[idx].debounceCounter = DEBOUNCE_INIT;
    eventList[idx].statusBits = INIT_BIT;
  }

  /* Init the error memory */
  for(idx = 0 ; idx < ERROR_MEMORY_SIZE ; idx++)
  {
    errorMemory[idx].eventID = NULL;
    errorMemory[idx].debounceCounter = NULL;
    errorMemory[idx].failedLvl = NULL;
    errorMemory[idx].passedLvl = NULL;
    errorMemory[idx].statusBits = NULL;
  }

  return retVal;
}


/*! \brief DEM main function.
 *
 *  This is the DEM main function that needs to be scheduled to run periodically.
 *  It is recommended that it is scheduled to run at least every 10ms.
 */
Std_Return_Type Dem_Main(void)
{
  Std_Return_Type retVal = E_NOT_OK;

  return retVal;
}

/*! \brief Access interface function for SW-C to report event status to the DEM.
 *
 *  If diagnostic function in a SW-C has evaluated an event it's status can be reported
 *  via this access function to the DEM to update the status. The status reported can either
 *  be PRE_PASSED or PRE_FAILED. Depending on the nature of the status the DEM then increases or
 *  decreases that events debounce counter. Alternatively the status PASSED respectively FAILED can
 *  be passed to the function allowing the instant setting of the diagnostic monitor status to PASSED
 *  or FAILED.
 *
 *  \param[in] Status <em> (type Std_Return) </em>， the status of the event either preFailed or prePassed
 */
Std_Return_Type Dem_SetEventStatus(Dem_EventID_Type eventID, Dem_EventStatus_Type status)
{
  Std_Return_Type retVal = E_NOT_OK;
  Dem_Event_Type *eventPtr = NULL;

  retVal = __findEvent(eventID, eventPtr);

  if(E_OK == retVal)
  {
    switch(status)
    {
      case PRE_PASSED:
      {
        if(eventPtr->debounceCounter > eventPtr->passedLvl)
        {
          eventPtr->debounceCounter--;
        }
        else
        {
          //__removeFromErrorMemory(eventPtr);
        }
        retVal = E_OK;
        break;
      }
      case PRE_FAILED:
      {
        if(eventPtr->debounceCounter < eventPtr->failedLvl)
        {
          eventPtr->debounceCounter++;
        }
        else
        {
          __addToErrorMemory(eventPtr);
        }
        retVal = E_OK;
        break;
      }
      case PASSED:
      {
        eventPtr->debounceCounter = eventPtr->passedLvl;
        //__removeFromErrorMemory(eventPtr);
        retVal = E_OK;
        break;
      }
      case FAILED:
      {
        eventPtr->debounceCounter = eventPtr->failedLvl;
        //__addToErrorMemory(eventPtr);
        retVal = E_OK;
        break;
      }
      default:
      {
        retVal = E_NOT_OK;
      }
    }
  }
  return retVal;
}

/*! \brief Access interface function for a SW-C to retrieve a events current status.
 *
 *  This functions can be used by SW-C to query the DEM for a particular events current status.
 */
Std_Return_Type Dem_GetEventStatus(Dem_EventID_Type eventID, Dem_EventStatus_Type *status)
{
  Std_Return_Type retVal = E_NOT_OK;
  Dem_Event_Type *eventPtr = NULL;

  retVal = __findEvent(eventID, eventPtr);

  if(E_OK == retVal)
  {
    if(eventPtr->debounceCounter <= eventPtr->passedLvl)
    {
      *status = PASSED;
      retVal = E_OK;
    }
    else if(eventPtr->debounceCounter >= eventPtr->failedLvl)
    {
      *status = FAILED;
      retVal = E_OK;
    }
    else
    {
      *status = NULL;
      retVal = E_NOT_OK;
    }
  }
  else
  {
    //Do nothing
  }

  return retVal;
}

/*! \brief Access interface function to clears the error memory.
 *
 *  This function can be called from a SW-C to clear the error memory.
 *  It can either clear a particular event or all events in the error memory.
 */
Std_Return_Type Dem_ClearErrorMemor()
{
  return E_OK;
}

Std_Return_Type __findEvent(Dem_EventID_Type eventID, Dem_Event_Type *eventPtr)
{
  uint16 Idx = 0;
  uint16 numberOfEvents = 0;
  Std_Return_Type retVal = E_NOT_OK;

  //Get the number of events configured in the DEM
  __getNumberOfEvents(&numberOfEvents);

  for(Idx = 0 ; Idx < numberOfEvents ; Idx++)
  {
    if(eventID == eventList[Idx].eventID)
    {
      eventPtr = &eventList[Idx];
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}

Std_Return_Type __getNumberOfEvents(uint16 *numberOfEvents)
{
  Std_Return_Type retVal = E_NOT_OK;

  *numberOfEvents = (sizeof(eventList)/sizeof(Dem_Event_Type));

  return retVal;
}

Std_Return_Type __addToErrorMemory(Dem_Event_Type *eventPtr)
{
  Std_Return_Type retVal = E_NOT_OK;

  static uint16 memoryIdx = 0;

//  for(idx = 0 ;



  return retVal;
}

Std_Return_Type __removeFromErrorMemory(Dem_Event_Type *eventPtr)
{
  Std_Return_Type retVal = E_NOT_OK;

  return retVal;
}
