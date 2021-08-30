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

#include "pal.h"
#include "pal_streambuffer.h"
#include "pal_errors.h"

palStatus_t pal_StreamBufferCreate(size_t bufferSize, size_t triggerLevel, palStreamBufferID_t *bufferID)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferCreate(bufferSize, riggerLevel, *bufferID);
    return result; 
}

palStatus_t pal_StreamBufferCreateStatic(size_t bufferSize, size_t triggerLevel, uint8_t *bufferStorageArea, palStreamBufferID_t *bufferID)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferCreateStatic(bufferSize, triggerLevel,  *bufferStorageArea, *bufferID );
    return result; 
}

palStatus_t pal_StreamBufferDelete(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferDelete(bufferID);
    return result;
}

palStatus_t pal_StreamBufferSend(palStreamBufferID_t bufferID, const void *txData, size_t dataLength, unit32_t waitTimeout)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID) || (NULL == *txData));
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferSend(bufferID, *txData, datalength, waitTimeout);
    return result;
}

palStatus_t pal_StreamBufferSendISR(palStreamBufferID_t bufferID, const void *txData, size_t dataLength)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID) || (NULL == *txData));
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferSendISR(bufferID, *txData, datalength);
    return result;
}

size_t pal_StreamBufferReceive(palStreamBufferID_t bufferID, void *rxData, size_t dataLength, unit32_t waitTimeout)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID) || (NULL == *rxData));
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferReceive(bufferID, *txData, datalength);
    return result;
}

size_t pal_StreamBufferReceiveISR(palStreamBufferID_t bufferID, void *rxData, size_t dataLength)
{
    PAL_VALIDATE_ARGUMENTS((NULLPTR == bufferID) || (NULL == *rxData));
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferReceiveISR(bufferID, *txData, datalength);
    return result;
}

bool pal_IsStreamBufferEmpty(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferEmpty(bufferID);
    return result;
}

bool pal_IsStreamBufferFull(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferFull(bufferID);
    return result;
}

palStatus_t pal_StreamBufferReset(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferReset(bufferID);
    return result;
}

palStatus_t pal_StreamBufferSetTriggerLevel(palStreamBufferID_t bufferID, size_t triggerLevel)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferSetTriggerLevel(bufferID, triggerLevel);
    return result;
}

size_t pal_StreamBufferAvailableBytes(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferAvailableBytes(bufferID);
    return result;
}

size_t pal_StreamBufferAvailableSpaces(palStreamBufferID_t bufferID)
{
    PAL_VALIDATE_ARGUMENTS(NULLPTR == bufferID);
    palStatus_t result = PAL_SUCCESS;
    result = pal_plat_StreamBufferAvailableSpaces(bufferID);
    return result;
}