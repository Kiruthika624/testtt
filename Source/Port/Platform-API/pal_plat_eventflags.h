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


#ifndef _PAL_PLAT_EVENTFLAGS_H
#define _PAL_PLAT_EVENTFLAGS_H

#include <stdint.h>
#include "pal.h"
#include "pal_eventflag.h"

#ifndef __cplusplus
extern "C" {
#endif

/*! \file pal_plat_eventflag.h
 *  \brief PAL PLAT EVENTFLAG.
 *  This file contains the Event APIs and is a part of the PAL service API.
 */
    
    /** The EventFlags class is used to control event flags or wait for event flags other threads control.
    
    */
    class pal_plat_EventFlags {
    public:
        /** Create and initialize an pal_plat_EventFlags object.
         *
        * @note You cannot call this function from ISR context.
        */
        virtual pal_plat_EventFlags() =0;
    
        /** Create and initialize an pal_plat_EventFlags object.
    
         @param name name to be used for this EventFlags. It has to stay allocated for the lifetime of the thread.
    
         @note You cannot call this function from ISR context.
        */
      virtual pal_plat_EventFlags(const char *name) =0;
    
        /** Set the specified event flags.
          @param   flags the flags that will be set.
          @return  event flags after setting or error code if highest bit set .
    
          @note This function may be called from ISR context.
         */
       virtual uint32_t pal_plat_set(uint32_t flags) =0;
    
        /** Clear the specified pal_plat_event flags.
   
    
          @note You may call this function from ISR context.
         */
       virtual uint32_t pal_plat_clear(uint32_t flags = default_value) =0;
    
        /** Get the currently set pal_plat_event flags.
          @return  current event flags.
    
          @note You may call this function from ISR context.
         */
       virtual uint32_t pal_plat_get() const =0;
    
        /** Wait for all of the specified event flags to become signaled.
          @param   flags    the flags to wait for (default: 0 -- no flags).
          @param   millisec timeout value (default: osWaitForever).
          @param   clear    clear specified event flags after waiting for them (default: true).
          @return  event flags before clearing or error code if highest bit set (see @a osFlagsError for details).
   
          @note You may call this function from ISR context if the millisec parameter is set to 0.
         */
       virtual uint32_t pal_plat_wait_all(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true) =0;
    
       /** Wait for any of the specified event flags to become signaled.
         @param   flags    the flags to wait for (default: 0 -- no flags).
         @param   millisec timeout value 
         @param   clear    clear specified event flags after waiting for them (default: true).
         @return  event flags before clearing or error code if highest bit set 
   
         @note This function may be called from ISR context if the millisec parameter is set to 0.
        */
       virtual uint32_t pal_plat_wait_any(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true);
   
       /** EventFlags destructor.
   
         @note You cannot call this function from ISR context.
       */
      virtual ~pal_plat_EventFlags() =0;
  
  };
  
 
   }
 #endif