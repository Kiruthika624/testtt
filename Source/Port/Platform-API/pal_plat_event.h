/*******************************************************************************
 * Copyright 2016, 2017 ARM Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/


#ifndef _PAL_PLAT_EVENT_H
#define _PAL_PLAT_EVENT_H

#include <stdint.h>
#include "pal.h"
#include "pal_event.h"

#ifndef __cplusplus
extern "C" {
#endif

/*! \file pal_plat_event.h
 *  \brief PAL PLAT EVENT.
 *  This file contains the Event APIs and is a part of the PAL service API.
 */


class pal_plat_event {

//! Primitive ID type declarations.
typedef uintptr_t palEventID_t;

//! PAL timer function prototype.
typedef void(*palEventFuncPtr)(void const *funcArgument);

/*! \brief Set Event Configuration.
*
* @param[in] queueID The ID handle of the queue .
* @param[in] function A function pointer to the event callback function.
* @param[in] funcArgument An argument for the event callback function.
*
* \return PAL_SUCCESS when the event was configured successfully.
* \return PAL_ERR_GENERIC_FAILURE when the queue ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventConfig(palQueueID_t queueID, palTimerFuncPtr function, void* funcArgument);

/*! \brief Post an event into the queue specified on event creation.
*
* @param[in] eventID    ID handle returns on successful posting event into queue.
* @param[out] argNum    No. of arguments passed in Event Data.
* @param[out] ...       Variable arguments passed to the event data.

* \return PAL_SUCCESS when the event data is posted successfully in the queue.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventPost(palEventID_t *eventID, int argNum, ...);

/*! \brief Post an event into the queue and verified data ID.
*
* @param[in] eventID    The ID handle of the event for which the data required to post.
* @param[out] argNum    No. of arguments passed in Event Data.
* @param[out] ...       Variable arguments passed to the event data.

* \return Function will assert is an invalid data ID returns in Event Data Post.
*/
virtual void pal_plat_EventCall(palEventID_t eventID, int argNum, ...);

/*! \brief Set delay for the event to start.
*
* @param[in] eventID    The ID handle of the event for which delay is set.
* @param[in] delay      Event delay value.
*
* \return PAL_SUCCESS when the delay is set for the event.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventDelay(palEventID_t eventID, uint32_t delay);

/*! \brief Set period for the event to start.
*
* @param[in] eventID    The ID handle of the event for which period is set.
* @param[in] period      Event period value.
*
* \return PAL_SUCCESS when the period is set for the event.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventPeriod(palEventID_t eventID, uint32_t period);

/*! \brief Cancels the most recently posted event in the given event queue.
*
* @param[in] eventID  The ID handle of the event which requires to cancel from the queue.

* \return PAL_SUCCESS when the event is canceled successfully in the queue.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventCancel(palEventID_t eventID);

/*! \brief Create an event queue. The event queue either allocates a buffer of 
*   the specified size with malloc or uses the user provided buffer or uses 1B dummy 
*   buffer if 0 size passed.
*
* @param[in] size  Size of buffer to use for events in bytes. If 0 provided then 1B dummy buffer is used.
* @param[in] buffer  Pointer to buffer to use for events.
* @param[in] queueID  ID handle returns on successful creating event queue..

* \return PAL_SUCCESS when the event queue created successfully.
* \return PAL_ERR_NO_MEMORY when there is no memory resource available to create an event queue object.
*/
virtual palStatus_t pal_plat_EventQueueCreate(unsigned int size, unsigned char *buffer, palQueueID_t *queueID);

/*! \brief Delete an event queue.
*
* @param[in] queueID  Event queue ID to be deleted.

* \return PAL_SUCCESS when the event queue deleted successfully.
* \return PAL_ERR_GENERIC_FAILURE when the queue ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventQueueDelete(palQueueID_t queueID);

/*! \brief Executes event for the specified number of milliseconds.
*
* @param[in] eventID  Event ID to be executed.
* @param[in] time  Time to wait for events in milliseconds.

* \return PAL_SUCCESS when the event executed successfully.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventExecutionFor(palEventID_t eventID, uint32_t time);

/*! \brief Executes event indefinitely unless the loop is forcibly broken.
*
* @param[in] eventID  Event ID to be executed.

* \return PAL_SUCCESS when the event execution started successfully.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventExecutionForever(palEventID_t eventID);

/*! \brief Executes event only once and then terminate.
*
* @param[in] eventID  Event ID to be executed.

* \return PAL_SUCCESS when the event executed successfully.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventExecutionOnce(palEventID_t eventID);

/*! \brief Break out of running event execution loop.
*
* @param[in] eventID  Event ID for which event the execution needed to break.

* \return PAL_SUCCESS when the event execution break successfully.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventExecutionBreak(palEventID_t eventID);

/*! \brief Cancel the event execution queued in Event Queue. It is not safe to call cancel after an event
* execution has already been started. Use pal_EventExecutionBreak in this case.
*
* @param[in] eventID  Event ID for which event execution requires to cancel.

* \return PAL_SUCCESS when the event execution cancel successfully.
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventExecutionCancel(palEventID_t eventID);

/*! \brief Query how much time is left for event execution. 
*
* @param[in] eventID  Unique ID of the event.
* @param[in] time  Pointer to store the left time of the event execution when returning.

* \return PAL_SUCCESS when the successfully returned left time for event exeuction..
* \return PAL_ERR_GENERIC_FAILURE when the event ID is invalid OR other failures.
*/
virtual palStatus_t pal_plat_EventTimeLeft(palEventID_t eventID, uint32_t *time);

#ifdef __cplusplus
}
}
#endif
#endif //_PAL_PLAT_EVENT_H