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

#ifndef _PAL_PLAT_CONDITIONVARIABLE_H
#define _PAL_PLAT_CONDITIONVARIABLE_H
    
#ifndef _PAL_H
    #error "Please do not include this file directly, use pal.h instead"
#endif

#include <stdint.h>
#include "pal_rtos.h"
#include "pal_conditionvariable.h"
    
#ifdef __cplusplus
extern "C" {
#endif

//! PAL prediction function prototype.
typedef bool(*palPredFuncPtr)(void);

/*! \brief Create & Initialize condition variable.
*
* @param[in] mutexID  Address of the mutex initialized for condition variale.
*
* \return PAL_SUCCESS - when the condition variable was created successfully.
* \return PAL_ERR_NULL_POINTER - when the address of the mutex if NULL pointer.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_ConditionVariableCreate(palMutexID_t &mutexID);

/*! \brief Delete condition variable.
*
* @param[in] mutexID  Address of the mutex initialized for condition variale.
*
* \return PAL_SUCCESS - when successfully deleted the condition variable.
* \return PAL_ERR_RTOS_RESOURCE Failure - the condition variable is alreay deleted.
* \return PAL_ERR_NULL_POINTER - when the address of the mutex if NULL pointer.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_ConditionVariableDelete(palMutexID_t &mutexID);

/*! \brief Wait for a notification. It causes the current thread(task) to block until 
* the condition variable receives a notification from another thread (task).
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - The current thread releases the mutex while inside the wait function and reacquires 
* it upon exiting the function.
* @note This function cannot call from ISR context.
*/
void pal_plat_WaitNotification(void);

/*! \brief Wait for a predicate. It causes the current thread to block until the predicate is true.
*
* @param[in] function  A function-like object such that `pred()` is convertible to bool
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - The current thread releases the mutex while inside the wait function and reacquires 
* it upon exiting the function.
* @note This function cannot call from ISR context.
*/
void pal_plat_WaitNotificationWithPredict(palPredFuncPtr function);

/*! \brief Wait for a notification or timeout. Wait causes the current thread(task) to block until 
* the condition variable receives a notification from another thread (task) or the timeout
* specified by the millisec parameter is reached.
*
* @param[in] timeout  Wait timeout value in milliseconds.
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - The current thread releases the mutex while inside the wait function and reacquires 
* it upon exiting the function.
* @note This function cannot call from ISR context.
*/
void pal_plat_WaitNotificationFor(uint32_t timeout);

/*! \brief Wait for a predicate. Wait causes the current thread to block until the predicate is true
* or the timeout specified by the millisec parameter is reached.
*
* @param[in] timeout  Wait timeout value in milliseconds.
* @param[in] function  A function-like object such that `pred()` is convertible to bool
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - The current thread releases the mutex while inside the wait function and reacquires 
* it upon exiting the function.
* @note This function cannot call from ISR context.
*/
void pal_plat_WaitNotificationForWithPredict(uint32_t timeout, palPredFuncPtr function);

/*! \brief Notify one waiter on this condition variable that a condition changed. 
* This function unblocks one of the threads (tasks) waiting for the condition variable.
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - The thread that is unblocked on this function is undefined if there are multiple waiters.
* @note This function cannot call from ISR context.
*/
void pal_plat_NotifyOne(void);

/*! \brief Notify all waiters on this condition variable that a condition changed. 
* This function unblocks all of the threads (tasks) waiting for the condition variable.
*
* @note - The thread calling this function must be the owner of the ConditionVariable's mutex, 
* and it must be locked exactly once.
* @note - If there are one or more waiters and one or more threads (tasks) attempting to acquire 
* the condition variable's mutex the order in which the mutex is acquired is undefined.
* @note This function cannot call from ISR context.
*/
void pal_plat_NotifyAll(void);

#ifdef __cplusplus
}
#endif
#endif //_PAL_PLAT_CONDITIONVARIABLE_H