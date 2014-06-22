//
//  AntiThetic.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__AntiThetic__
#define __ch7_exotics_engine_and_template_pattern__AntiThetic__

#include "Random2.h"
#include "Wrapper.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator);// wrapper object point to a random number generator
    
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual void Reset();
    
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;// boolean to indicate next draw should from inner generator or anti-thetic of last draw
    MJArray NextVariates; // array as data member to store last vector drawm
};

#endif /* defined(__ch7_exotics_engine_and_template_pattern__AntiThetic__) */
