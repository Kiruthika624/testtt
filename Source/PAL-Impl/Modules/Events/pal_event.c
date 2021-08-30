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


#include "pal.h"
#include "pal_event.h"
#include "pal_plat_event.h"
#include "pal_errors.h"

#define TRACE_GROUP "PAL"
#define NULLPTR 0

typedef int32_t palStatus_t;


palStatus_t pal_EventConfig(palQueueID_t queueID, palTimerFuncPtr function, void* funcArgument)
{
PAL_VALIDATE_ARGUMENTS((NULL == queueID) || (NULLPTR  == function) || (NULLPTR == funcArgument));

     palStatus_t result = pal_plat_EventConfig(queueID, function, funcArgument);
     return result;
  
}


palStatus_t pal_EventPost(palEventID_t *eventID, int argNum, ...)
{
    PAL_VALIDATE_ARGUMENTS(( NULLPTR == eventID) || (NULL == argNum) || (NULL == ...));

    palStatus_t result = pal_plat_EventPost(*eventID, argNum, ...);
    return result;


}
void pal_EventCall(palEventID_t eventID, int argNum, ...)
{
  PAL_VALIDATE_ARGUMENTS(( NULLPTR == eventID) || (NULL == argNum) || (NULL == ...)); 
 
  palStatus_t result =  pal_plat_EventCall(*eventID, argNum, ...);
  return result;
   
  
}

palStatus_t pal_EventDelay(palEventID_t eventID, uint32_t delay)
{
    PAL_VALIDATE_ARGUMENTS(( NULLPTR == eventID) || (NULL == delay));
  
    palStatus_t result =  pal_plat_EventDelay(eventID, delay);
    return result;
   
}

palStatus_t pal_EventPeriod(palEventID_t eventID, uint32_t period)
{
  PAL_VALIDATE_ARGUMENTS(( NULLPTR == eventID) || (NULL == period));
  
    palStatus_t result =  pal_plat_EventPeriod(eventID, period);
    return result;
}


palStatus_t pal_EventCancel(palEventID_t eventID)
{
palStatus_t result = PAL_SUCCESS;
PAL_VALIDATE_ARGUMENTS( NULLPTR == eventID);
return result;
}



palStatus_t pal_EventQueueCreate(unsigned int size, unsigned char *buffer, palQueueID_t *queueID)
{
    PAL_VALIDATE_ARGUMENTS(NULL == queueID);
    palStatus_t result =PAL_SUCCESS;
    status = pal_plat_EventqueueCreate(size, semaphoreID);
    return status;
}


palStatus_t pal_EventQueueDelete(palQueueID_t queueID);
{
    PAL_VALIDATE_ARGUMENTS(NULL == queueID || NULLPTR == *queueID);
    palStatus_t result = PAL_SUCCESS;
    status = pal_plat_EventqueueDelete(queueID);
    return status;
}


palStatus_t pal_EventExecutionFor(palEventID_t eventID, uint32_t time)
{
   PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionFor(eventID,time);
   return status;

}


palStatus_t pal_EventExecutionForever(palEventID_t eventID)
{
    PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionForever(eventID);
   return status;

}


palStatus_t pal_EventExecutionOnce(palEventID_t eventID)
{
PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionOnce(eventID);
   return status;
}

palStatus_t pal_EventExecutionBreak(palEventID_t eventID)
{
PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionBreak(eventID);
   return status;
}

palStatus_t pal_EventExecutionCancel(palEventID_t eventID);
{
PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionCancel(eventID);
   return status;
}


palStatus_t pal_EventTimeLeft(palEventID_t eventID, uint32_t *time)
{
PAL_VALIDATE_ARGUMENTS(NULL == eventID);
   palStatus_t result = PAL_SUCCESS;
   status = pal_plat_EventExecutionOnce(eventID,time);
   return status;
}

#ifdef __cplusplus


}