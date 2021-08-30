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

#ifndef _PAL_PLAT_STREAMBUFFER_H
#define _PAL_PLAT_STREAMBUFFER_H
    
#ifndef _PAL_H
    #error "Please do not include this file directly, use pal.h instead"
#endif

#include <stdint.h>
#include <stddef.h>
#include "pal_types.h"
    
#ifdef __cplusplus
extern "C" {
#endif

/*! \file pal_plat_streambuffer.h
 *  \brief PAL STREAM BUFFER.
 *  This file contains the stream buffer related APIs and is a part of the PAL service API.
 */
#define size_t  long unsigned int 

//! Primitive ID type declarations.
typedef uintptr_t palStreamBufferID_t;

/*! \brief Creates a new stream buffer using dynamically allocated memory. 
*
* @param[in] bufferSize     The total number of bytes that stream buffer can hold.
* @param[in] triggerLevel   The number of bytes that must be in the stream buffer before a task (thread) that is 
*                           blocked on the stream buffer to wait for data is moved out of the blocked state.
* @param[in, out] bufferID  The unique ID handle of the created stream buffer. In case of error, this value is `NULL`.
*
* \return PAL_SUCCESS - when the stream buffer was created successfully.
* \return PAL_ERR_NO_MEMORY - when there is no memory resource available to create stream buffer.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_StreamBufferCreate(size_t bufferSize, size_t triggerLevel, palStreamBufferID_t *bufferID);

/*! \brief Creates a new stream buffer using statically allocated memory.
*
* @param[in] bufferSize     The total number of bytes that stream buffer can hold.
* @param[in] triggerLevel   The number of bytes that must be in the stream buffer before a task (thread) that is 
*                           blocked on the stream buffer to wait for data is moved out of the blocked state.
* @param[in] bufferStorageArea  Pointer to a uint8_t array to which streams are copied when they are written to the stream buffer.
* @param[in, out] bufferID  The unique ID handle of the created stream buffer. In case of error, this value is `NULL`.
*
* \return PAL_SUCCESS - when the stream buffer was created successfully.
* \return PAL_ERR_NO_MEMORY - when there is no memory resource available to create stream buffer.
* \return PAL_ERR_NULL_POINTER - when the address of the 'bufferStorageArea' is NULL.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_StreamBufferCreateStatic(size_t bufferSize, size_t triggerLevel, uint8_t *bufferStorageArea, palStreamBufferID_t *bufferID);

/*! \brief Deletes a stream buffer that was previously created using a call to xStreamBufferCreate() or xStreamBufferCreateStatic().
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return PAL_SUCCESS - when successfully deleted the stream buffer.
* \return PAL_ERR_RTOS_RESOURCE Failure - the stream buffer was already deleted.
* \return PAL_ERR_RTOS_PARAMETER Failure - the buffer ID is invalid.
* \note After this call, the `bufferID` is no longer valid and cannot be used.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_StreamBufferDelete(palStreamBufferID_t bufferID);

/*! \brief Sends bytes to a stream buffer. The bytes are copied into the stream buffer.
*
* @param[in] bufferID       Unique stream buffer ID.
* @param[in] txData         A pointer to the buffer that holds the bytes to be copied into the stream buffer.
* @param[in] dataLength     The maximum number of bytes to copy into the stream buffer.
* @param[in] waitTimeout    The wait timeout for the task to remain in the Blocked state for enough space to become available.
*
* \return PAL_SUCCESS - when the number of bytes written to the stream buffer successfully.
* \return PAL_ERR_TIMEOUT_EXPIRED - when the wait timeout occurs before writing all data into stream buffer.
* @note This function cannot call from ISR context.
*/
palStatus_t pal_plat_StreamBufferSend(palStreamBufferID_t bufferID, const void *txData, size_t dataLength, unit32_t waitTimeout);

/*! \brief Sends bytes to a stream buffer in Interrupt Service Routine(ISR).
*
* @param[in] bufferID       Unique stream buffer ID.
* @param[in] txData         A pointer to the buffer that holds the bytes to be copied into the stream buffer.
* @param[in] dataLength     The maximum number of bytes to copy into the stream buffer.
*
* \return PAL_SUCCESS - when the number of bytes written to the stream buffer successfully.
*/
palStatus_t pal_plat_StreamBufferSendISR(palStreamBufferID_t bufferID, const void *txData, size_t dataLength);

/*! \brief Receives bytes from a stream buffer.
*
* @param[in] bufferID       Unique stream buffer ID.
* @param[in, out] rxData    A pointer to the buffer into which the received bytes will be copied.
* @param[in] dataLength     The length of the buffer pointed to by the rxData parameter. This sets the maximum number of bytes to receive in one call.
* @param[in] waitTimeout    wait timeout for the task should remain in the Blocked state for data to become available if the stream buffer is empty.     
*
* \return The number of bytes read from the stream buffer. This will be the number of bytes available up to a maximum of dataLength.
* @note This function cannot call from ISR context.
*/
size_t pal_plat_StreamBufferReceive(palStreamBufferID_t bufferID, void *rxData, size_t dataLength, unit32_t waitTimeout);

/*! \brief Receives bytes from a stream buffer in Interrupt Service Routine(ISR).
*
* @param[in] bufferID       Unique stream buffer ID.
* @param[in, out] rxData    A pointer to the buffer into which the received bytes will be copied.
* @param[in] dataLength     The length of the buffer pointed to by the rxData parameter. This sets the maximum number of bytes to receive in one call.
*
* \return The number of bytes read from the stream buffer. This will be the number of bytes available up to a maximum of dataLength.
*/
size_t pal_plat_StreamBufferReceiveISR(palStreamBufferID_t bufferID, void *rxData, size_t dataLength);

/*! \brief Queries a stream buffer to see if it is empty OR not.
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return True if stream buffer is empty otherwise false. 
*/
bool pal_plat_IsStreamBufferEmpty(palStreamBufferID_t bufferID);

/*! \brief Queries a stream buffer to see if it is full OR not.
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return True if stream buffer is full otherwise false. 
*/
bool pal_plat_IsStreamBufferFull(palStreamBufferID_t bufferID);

/*! \brief Resets a stream buffer to its initial, empty, state. Any data that was in the stream buffer is discarded.
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return PAL_SUCCESS - when the number of bytes written to the stream buffer successfully.
* \return PAL_ERR_GENERIC_FAILURE - when a task blocked waiting to send to or read from the stream buffer.
* @note This function cannot call from ISR context.
* @note A stream buffer can only be reset if there are no tasks blocked waiting to either send to or receive from the stream buffer.
*/
palStatus_t pal_plat_StreamBufferReset(palStreamBufferID_t bufferID);

/*! \brief Set new trigger level for the stream buffer.
*
* @param[in] bufferID       Unique stream buffer ID.
* @param[in] triggerLevel   The new trigger level for the stream buffer. 
*                           It should be less than or equal to the stream buffer's length.

* \return PAL_SUCCESS - when the trigger leave was set successfully.
* \return PAL_ERR_INVALID_ARGUMENT - when the trigger level value is greater that stream buffer size.
* @note A stream buffer's trigger level is the number of bytes that must be in the stream buffer before a task 
*       that is blocked on the stream buffer to wait for data is moved out of the blocked state.
*/
palStatus_t pal_plat_StreamBufferSetTriggerLevel(palStreamBufferID_t bufferID, size_t triggerLevel);

/*! \brief Queries a stream buffer to see how much data it contains. 
* It is equal to the no. of bytes that can be read from the stream buffer before the stream buffer would be empty.
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return Number of bytes stream buffer contains that can be read from it. 
*/
size_t pal_plat_StreamBufferAvailableBytes(palStreamBufferID_t bufferID);

/*! \brief Queries a stream buffer to see how much free space it contains. 
* It is equal to the amount of data that can be sent to the stream buffer before it is full.
*
* @param[in] bufferID   Unique stream buffer ID.
*
* \return The number of bytes that can be written to the stream buffer before the stream buffer would be full.
*/
size_t pal_plat_StreamBufferAvailableSpaces(palStreamBufferID_t bufferID);

#ifdef __cplusplus
}
#endif
#endif //_PAL_PLAT_STREAMBUFFER_H