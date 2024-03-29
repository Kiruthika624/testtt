 * mbed Microcontroller Library
      * Copyright (c) 2006-2019 ARM Limited
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
     * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
     * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
     * SOFTWARE.
     */
    #ifndef EVENT_FLAG_H
    #define EVENT_FLAG_H
    
    #include <cstddef>
    #include <stdint.h>
    
    
    /** The EventFlags class is used to control event flags or wait for event flags other threads control.
    
    */
    class EventFlags {
    public:
        /** Create and initialize an EventFlags object.
         *
        * @note You cannot call this function from ISR context.
        */
        virtual EventFlags() =0;
    
        /** Create and initialize an EventFlags object.
    
         @param name name to be used for this EventFlags. It has to stay allocated for the lifetime of the thread.
    
         @note You cannot call this function from ISR context.
        */
      virtual EventFlags(const char *name) =0;
    
        /** Set the specified event flags.
          @param   flags the flags that will be set.
          @return  event flags after setting or error code if highest bit set .
    
          @note This function may be called from ISR context.
         */
       virtual uint32_t set(uint32_t flags) =0;
    
        /** Clear the specified event flags.
   
    
          @note You may call this function from ISR context.
         */
       virtual uint32_t clear(uint32_t flags = default_value) =0;
    
        /** Get the currently set event flags.
          @return  current event flags.
    
          @note You may call this function from ISR context.
         */
       virtual uint32_t get() const =0;
    
        /** Wait for all of the specified event flags to become signaled.
          @param   flags    the flags to wait for (default: 0 -- no flags).
          @param   millisec timeout value (default: osWaitForever).
          @param   clear    clear specified event flags after waiting for them (default: true).
          @return  event flags before clearing or error code if highest bit set (see @a osFlagsError for details).
   
          @note You may call this function from ISR context if the millisec parameter is set to 0.
         */
       virtual uint32_t wait_all(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true) =0;
    
       /** Wait for any of the specified event flags to become signaled.
         @param   flags    the flags to wait for (default: 0 -- no flags).
         @param   millisec timeout value 
         @param   clear    clear specified event flags after waiting for them (default: true).
         @return  event flags before clearing or error code if highest bit set 
   
         @note This function may be called from ISR context if the millisec parameter is set to 0.
        */
       virtual uint32_t wait_any(uint32_t flags = 0, uint32_t millisec = timeout value, bool clear = true);
   
       /** EventFlags destructor.
   
         @note You cannot call this function from ISR context.
       */
      virtual ~EventFlags() =0;
  
  };
  
 
   }
 #endif