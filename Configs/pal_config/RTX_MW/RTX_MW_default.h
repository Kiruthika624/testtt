/*******************************************************************************
 * Copyright 2020 ARM Ltd.
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

#ifndef PAL_RTX_MW_CONFIGURATION_H_
#define PAL_RTX_MW_CONFIGURATION_H_

#include "cmsis_os2.h"

#ifndef PAL_RTOS_WAIT_FOREVER
    #define PAL_RTOS_WAIT_FOREVER osWaitForever
#endif

#ifndef PAL_MAX_SEMAPHORE_COUNT
    #define PAL_MAX_SEMAPHORE_COUNT 1024
#endif

#ifndef PAL_USE_HW_ROT
    #define PAL_USE_HW_ROT          0
#endif

#ifndef PAL_USE_HW_RTC
    #define PAL_USE_HW_RTC          0
#endif

#ifndef PAL_USE_HW_TRNG
    #define PAL_USE_HW_TRNG         1
#endif

#ifndef PAL_USE_INTERNAL_FLASH
    #define PAL_USE_INTERNAL_FLASH  0
#endif

#ifndef PAL_USE_SECURE_TIME
    #define PAL_USE_SECURE_TIME     1
#endif

// SSL session resume requires Mbed TLS 2.18.0 or later
#ifndef PAL_USE_SSL_SESSION_RESUME
#define PAL_USE_SSL_SESSION_RESUME 0
#endif

#ifndef MBED_CONF_MBED_CLOUD_CLIENT_EXTERNAL_SST_SUPPORT
    #define MBED_CONF_MBED_CLOUD_CLIENT_EXTERNAL_SST_SUPPORT 1
#endif

#ifndef PAL_DEFAULT_RTT_ESTIMATE
    #define PAL_DEFAULT_RTT_ESTIMATE 5
#endif

#define SYS_CONF_SOTP SYS_CONF_SOTP_DISABLED

#endif /* PAL_RTX_MW_CONFIGURATION_H_ */

