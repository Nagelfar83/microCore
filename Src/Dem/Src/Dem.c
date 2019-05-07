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

#include "Dem_Config.h"
#include "Dem.h"

Std_ReturnType __findEvent(uint16 eventID, Dem_eventType *event);

/*! \brief DEM main function.
 *
 *  This is the DEM main function that needs to be scheduled to run periodically.
 *  It is recommended that it is scheduled to run at least every 10ms.
 */
int dem_main(void)
{
  return E_OK;
}

/*! \brief Access interface function for SW-C to report event status to the DEM.
 *
 *  If diagnostic function in a SW-C has evaluated an event it's status can be reported
 *  via this access function to the DEM to update the status. The status reported can either
 *  be preFailed or prePassed. Depending on the nature of the status the DEM then increases or
 *  decreases that events debounce counter.
 *
 *  \param[in] Status <em> (type Std_Return) </em>， the status of the event either preFailed or prePassed
 */
Std_ReturnType Dem_SetEventStatus(uint8_t Status)
{
  Std_ReturnType retVal = 0;

  retVal = __findEvent();

  return E_OK;
}

/*! \brief Access interface function for a SW-C to retrieve event status.
 *
 *  This functions can be used by SW-C to query the DEM for a particular events current status.
 */
Std_ReturnType Dem_GetEventStatus()
{
  return E_OK;
}

/*! \brief Access interface function to clears the error memory.
 *
 *  This function can be called from a SW-C to clear the error memory.
 *  It can either clear a particular event or all events in the error memory.
 */
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



