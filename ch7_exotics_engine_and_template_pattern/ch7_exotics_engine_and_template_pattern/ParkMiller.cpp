//
//  ParkMiller.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "ParkMiller.h"

// constants for generating algorithm
const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_ ) : Seed(Seed_)
{
    if (Seed ==0)// check whether seed is 0
        Seed=1;
}

void ParkMiller::SetSeed(long Seed_)
{
    Seed=Seed_;
    if (Seed ==0)
        Seed=1;
}

unsigned long ParkMiller::Max()
{
    return m-1;
}

unsigned long ParkMiller::Min()
{
    return 1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k;
    
    k=Seed/q;
    
    Seed=a*(Seed-k*q)-r*k;
    
    if (Seed < 0)
        Seed += m;
    
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed)
:    RandomBase(Dimensionality),
InnerGenerator(Seed),
InitialSeed(Seed)
{
    Reciprocal = 1/(1.0+InnerGenerator.Max());
}

RandomBase* RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray& variates)
{
    for (unsigned long j=0; j < GetDimensionality(); j++)
        // divide the outputs of inner generator by (max+1) to ensure get Uni(0,1) on open interval
        // avoid trouble with inverse tranform for normal distribution
        variates[j] = InnerGenerator.GetOneRandomInteger()*Reciprocal;
    
}

void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimensionality());
    for (unsigned long j=0; j < numberOfPaths; j++)
        GetUniforms(tmp);
}

void RandomParkMiller::SetSeed(unsigned long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}


void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality)
{
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}

