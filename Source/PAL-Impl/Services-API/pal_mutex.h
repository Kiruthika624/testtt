/*
 * Copyright (c) 2018, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
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
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include <stdint.h>

namespace rtos {

class Mutex {
public:
	
    /** Create and Initialize a Mutex object
     * @note You cannot call this function from ISR context.
    */
	virtual Mutex() = 0;
	
    /** Create and Initialize a Mutex object

     @param name 	name to be used for this mutex. It has to stay allocated for 
    				the lifetime of the thread.
     @note You cannot call this function from ISR context.
    */
	virtual Mutex(const char *name) = 0;
	
    /**
      Wait until a Mutex becomes available.
      @note You cannot call this function from ISR context.
    */
    virtual void lock() = 0;
    
    /** Try to lock the mutex, and return immediately
      @return true if the mutex was acquired, false otherwise.
      @note equivalent to trylock_for(0)
      @note You cannot call this function from ISR context.
    */
    virtual bool trylock() = 0;
    
    /** Try to lock the mutex for a specified time
      @param time  timeout value.
      @return true if the mutex was acquired, false otherwise.
      @note the underlying RTOS may have a limit to the maximum wait time
            due to internal 32-bit computations, but this is guaranteed to work 
            if the wait is <= 0x7fffffff milliseconds (~24 days). 
            If the limit is exceeded, the lock attempt will time out earlier 
            than specified.
      @note You cannot call this function from ISR context.
    */
    virtual bool trylock_for(uint32_t time) = 0;
    
    /** Try to lock the mutex until specified time
      @param time  absolute timeout time, referenced to Kernel::Clock
      @return true if the mutex was acquired, false otherwise.
      @note the underlying RTOS may have a limit to the maximum wait time
            due to internal 32-bit computations, but this is guaranteed to work 
            if the wait is <= 0x7fffffff milliseconds (~24 days). 
            If the limit is exceeded, the lock attempt will time out earlier 
            than specified.
      @note You cannot call this function from ISR context.
     */
    virtual bool trylock_until(uint32_t time) = 0;
    
    /**
      Unlock the mutex that has previously been locked by the same thread.
      @note You cannot call this function from ISR context.
     */
    virtual void unlock() = 0;
    
    /** Get the owner the this mutex
      @return  the current owner of this mutex.
      @note You cannot call this function from ISR context.
     */
    virtual void * get_mutex_owner() = 0;
    
    /** Mutex destructor
     * @note You cannot call this function from ISR context.
     */
    virtual ~Mutex() = 0;
};
}

#endif /* MUTEX_H_ */
