/*******************************************************************************
* Copyright 2019 ARM Ltd.
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
#include "pal_plat_entropy.h"
#include "mbed_trace.h"

#define TRACE_GROUP "PAL"

palStatus_t pal_osEntropyInject(const uint8_t *entropyBuf, size_t bufSizeBytes)
{
    PAL_VALIDATE_ARGUMENTS(NULL == entropyBuf);
    if (PAL_PLAT_MAX_ENTROPY_SIZE < bufSizeBytes)
    {
        return PAL_ERR_ENTROPY_TOO_LARGE;
    }
    return pal_plat_osEntropyInject(entropyBuf, bufSizeBytes);
}
