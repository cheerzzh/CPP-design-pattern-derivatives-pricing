//
//  Random2.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__Random2__
#define __ch6_random_number_class__Random2__

#include "Arrays.h" // use MJArray

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality);
    
    inline unsigned long GetDimensionality() const;
    
    virtual RandomBase* clone() const;
    
    // pure virtual methods
    virtual void GetUniform(MJArray& variates)=0;
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

#endif /* defined(__ch6_random_number_class__Random2__) */
