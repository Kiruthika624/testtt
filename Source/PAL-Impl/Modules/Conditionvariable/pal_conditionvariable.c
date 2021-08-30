// ----------------------------------------------------------------------------
// Copyright 2016-2019 ARM Ltd.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------


#include <stdint.h>
#include "pal_rtos.h"
#include "pal_conditionvariable.h"
#include "pal_plat_conditionvariable.h"

palStatus_t status;

palStatus_t pal_ConditionVariableCreate(palMutexID_t &mutexID)
{
   PAL_VALIDATE_ARGUMENTS(NULLPTR == mutexID);
   status = pal_plat_ConditionVariableCreate(mutexID);
   return status; 
}

palStatus_t pal_ConditionVariableDelete(palMutexID_t &mutexID)
{
   PAL_VALIDATE_ARGUMENTS(NULLPTR == mutexID);
   status = pal_plat_ConditionVariableDelete(mutexID);
   return status;   
}

void pal_WaitNotification(void)
{
   status = pal_plat_ConditionVariableDelete(mutexID);
   return status;  
}

void pal_WaitNotificationWithPredict(palPredFuncPtr function)
{
   PAL_VALIDATE_ARGUMENTS(NULLPTR== function);
   status = pal_plat_WaitNotoficationWithPredict(function);
   return status;
}

void pal_WaitNotificationFor(uint32_t timeout)
{
   status = pal_plat_WithNotificationFor(timeout);
   return status; 
}

void pal_WaitNotificationForWithPredict(uint32_t timeout, palPredFuncPtr function)
{
   PAL_VALIDATE_ARGUMENTS(NULLPTR== function);
   status = pal_plat_WaitNotoficationWithPredict(timeout,function);
   return status;
}

void pal_NotifyOne(void)
{
   return pal_plat_NotifyOne();
}

void pal_NotifyAll(void)
{
    return pal_plat_NotifyAll();
}