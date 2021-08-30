/* mbed Microcontroller Library
 * Copyright (c) 2006-2019 ARM Limited
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdint.h>
typedef unsigned int uint32_t
typedef signed int int32_t
typedef unsigned long int uint64_t
typedef unsigned short int uint16_t
namespace rtos {

/** The Semaphore class is used to manage and protect access to a set of shared resources.
 *
 * @note
 * Memory considerations: The semaphore control structures will be created on current thread's stack, both for the mbed OS
 * and underlying RTOS objects (static or dynamic RTOS memory pools are not being used).
 */
class Semaphore {

	/**constructor**/
	            Semaphore(int32_t count = 0);

	    /** Create and Initialize a Semaphore object used for managing resources.
	      @param  count     number of available resources
	      @param  max_count maximum number of available resources

	      @note You cannot call this function from ISR context.
	    */
	           Semaphore(int32_t count, uint16_t max_count);

	  /** Wait until a Semaphore resource becomes available.

	      @note You cannot call this function from ISR context.
	 **/
	            virtual void acquire() =0;

	  /** Try to acquire a Semaphore resource, and return immediately
	        @return true if a resource was acquired, false otherwise.
	        @note equivalent to try_acquire_for(0)

	      @note You may call this function from ISR context.
	      */
	            virtual bool try_acquire() =0;

	       /** Wait until a Semaphore resource becomes available.
	        @param   millisec  timeout value.
	        @return true if a resource was acquired, false otherwise.


         @note You may call this function from ISR context if the millisec parameter is set to 0.
         @deprecated Pass a chrono duration, not an integer millisecond count. For example use `5s` rather than `5000`.
         */

            virtual bool try_acquire_for(uint32_t time) =0;
            /** Wait until a Semaphore resource becomes available.
               @param   millisec  absolute timeout time, referenced to Kernel::Clock
               @return true if a resource was acquired, false otherwise.
               @note the underlying RTOS may have a limit to the maximum wait time
                     due to internal 32-bit computations, but this is guaranteed to work if the
                     wait is <= 0x7fffffff milliseconds (~24 days). If the limit is exceeded,
                     the acquire attempt will time out earlier than specified.

               @note You cannot call this function from ISR context.
             */
           virtual bool try_acquire_until(uint64_t time) =0;
            /** Release a Semaphore resource that was obtain with Semaphore::acquire.
                 @return status code that indicates the execution status of the function:
                         @a osOK the token has been correctly released.
                         @a osErrorResource the maximum token count has been reached.
                         @a osErrorParameter internal error.
               */
           virtual uint32_t release(void) =0;

               /** Semaphore destructor
                *
                * @note You cannot call this function from ISR context.
                */
           virtual ~Semaphore() =0;

};

};
#endif     /* SEMAPHORE_H */

