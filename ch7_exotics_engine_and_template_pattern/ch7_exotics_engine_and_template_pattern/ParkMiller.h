//
//  ParkMiller.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__ParkMiller__
#define __ch7_exotics_engine_and_template_pattern__ParkMiller__

#include "Random2.h"


// the smaller class which return one number each time called
// a sequence of uncorrelated long
class ParkMiller
{
public:
    ParkMiller(long Seed =1);
    
    long GetOneRandomInteger();
    void SetSeed(long Seed);
    
    // specify min and max value possible
    static unsigned long Max();
    static unsigned long Min();
    
private:
    long Seed;
};

class RandomParkMiller: public RandomBase
{
public:
    RandomParkMiller(unsigned long Dimensionality, unsigned long Seed=1);
    
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal; // reciprocal of max value plus one, help to turn output of inner generator into uniforms
};



#endif /* defined(__ch7_exotics_engine_and_template_pattern__ParkMiller__) */
