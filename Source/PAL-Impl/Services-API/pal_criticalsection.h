
#ifndef CRITICALSECTIONLOCK_H
#define CRITICALSECTIONLOCK_H


class CriticalSectionLock {
public:
      /** constructor **/
     virtual CriticalSectionLock() =0;
 
     /** Distructor **/
     virtual ~CriticalSectionLock()=0;

    /**Enter the critical section 
       Code in this block will run with interrupts disabled **/
    virtual void critical_section_enter() =0;

    /**Exit the critical section 
       interrupts will have been re-enabled after calling of critical_section_exit() function **/
     virtual void critical_section_exit() =0;

}

