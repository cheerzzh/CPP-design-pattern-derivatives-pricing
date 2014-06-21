//
//  Random2.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__Random2__
#define __ch7_exotics_engine_and_template_pattern__Random2__

#include "Arrays.h" // use MJArray

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality_);
    
    inline unsigned long GetDimensionality() const; // simple method, no need to be virtual
    virtual RandomBase* clone() const=0;
    
    // pure virtual methods
    virtual void GetUniforms(MJArray& variates)=0;// reference to a array, do not to waste time in copying the array, pass the return value into pre-generated array
    virtual void Skip(unsigned long numberOfPaths) = 0;
    virtual void SetSeed(unsigned long Seed) = 0;
    virtual void Reset() = 0;
    
    virtual void GetGaussians(MJArray& variates); // make virtual to allow another conversion method
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality()const
{
    return Dimensionality;
}


#endif /* defined(__ch7_exotics_engine_and_template_pattern__Random2__) */
