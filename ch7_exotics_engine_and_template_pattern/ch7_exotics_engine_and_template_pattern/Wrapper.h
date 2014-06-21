//
//  Wrapper.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__Wrapper__
#define __ch7_exotics_engine_and_template_pattern__Wrapper__

template <class T>

class Wrapper
{
public:
    Wrapper(){ DataPtr = 0;} // the default constructor which point to nothing
    Wrapper(const T& inner) // constructor
    {
        DataPtr = inner.clone();
    }
    ~Wrapper()
    {
        if (DataPtr != 0) // if DataPtr Point to some memory, release it
        {
            delete DataPtr;
        }
    }
    
    Wrapper(const Wrapper<T>& original) // constructor when pass in a Wrapper class
    {
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr -> clone();
        else
            DataPtr = 0;
    }
    
    // return by reference to avoid unnecessary copy
    Wrapper& operator= (const Wrapper<T>& oringinal)// overloading "="
    {
        if (this != &oringinal)
        {
            if (DataPtr!= 0)
            {
                delete DataPtr;
                DataPtr = (oringinal.DataPtr != 0)? oringinal.DataPtr.clone():0;
            }
            
        }
        return  *this; // return what this point to
    }
    
    // two version of dereferencing operator *
    // dereference both const and non-const objects
    T& operator*() // overloading "*" to get object from pointer
    {
        return *DataPtr;
    }
    
    const T& operator*() const // return a const object
    {
        return *DataPtr;
    }
    
    // overloading "->" to access method within pointed object
    const T*  operator ->() const
    {
        return DataPtr;
    }
    
    T* operator ->()
    {
        return DataPtr;
    }
    
    
private:
    T* DataPtr;
};

#endif /* defined(__ch7_exotics_engine_and_template_pattern__Wrapper__) */
