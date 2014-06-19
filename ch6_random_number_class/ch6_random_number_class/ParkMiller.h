//
//  ParkMiller.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__ParkMiller__
#define __ch6_random_number_class__ParkMiller__

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



#endif /* defined(__ch6_random_number_class__ParkMiller__) */
