*******************************************************************************
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
#include "pal_eventflags.h"
#include "pal_plat_eventflags.h"
#include "pal_errors.h"

#define TRACE_GROUP "PAL"

    uint32_t pal_set(uint32_t flags)
    {
     PAL_VALIDATE_ARGUMENTS((NULL == flags);
     palStatus_t result = pal_plat_set(flags);
     return result;

    }
    
    uint32_t pal_clear(uint32_t flags = default_value)
    {
     PAL_VALIDATE_ARGUMENTS((NULL == flags);
     palStatus_t result = pal_plat_clear(flags);
     return result;
  
    }

    uint32_t pal_get() const
    {
     palStatus_t result = pal_plat_get(void);
     return result;
    }
    
    uint32_t wait_all(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true)
    {
    palStatus_t result = pal_plat_wait_all(flags,timeout value,clear);
    return result;
    }
    
    uint32_t wait_any(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true)
    {
     palStatus_t result = pal_plat_wait_any(flags,timeout value,clear);
     return result;
    }
   
     ~EventFlags()
     {
         ~pal_plat_EventFlags();
     }
  
  };
  
 
   }
 #endif