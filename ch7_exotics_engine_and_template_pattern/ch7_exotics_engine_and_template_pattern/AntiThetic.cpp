//
//  AntiThetic.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "AntiThetic.h"

// *innerGenerator: get underlying RandomBase pbject ("*" is overloading in Wrapper class)
// specify the inherited random number generator
AntiThetic::AntiThetic(const Wrapper<RandomBase>& innerGenerator):RandomBase(*innerGenerator),InnerGenerator(innerGenerator)
{
    // perform intialization
    InnerGenerator->Reset();
    OddEven = true;
    NextVariates.resize(GetDimensionality());
    
}

RandomBase* AntiThetic::clone()const
{
    return new AntiThetic(*this);
}

void AntiThetic::GetUniforms(MJArray &variates)
{
    if (OddEven)// if true, use anti-thetic
    {
        InnerGenerator->GetUniforms(variates); // generate one path using undering random generator
        // make anti-thetic
        for (unsigned long i=0; i<GetDimensionality(); i++)
        {
            NextVariates[i] = 1.0 - variates[i];
        }
        OddEven = false;
    }
    else
    {
        variates = NextVariates;
        OddEven= true;
    }
}


void AntiThetic::SetSeed(unsigned long Seed)
{
    InnerGenerator->SetSeed(Seed);
    OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
    //not skip
    if (numberOfPaths==0) return;
    
    // if next step have to do anti-thetic, reverse the flag and reduce one path
    if (OddEven)
    {
        OddEven = false;
        numberOfPaths--;
    }
    
    
    InnerGenerator -> Skip(numberOfPaths/2);
    
    if (numberOfPaths %2)
    {
        MJArray tmp(GetDimensionality());
        GetUniforms(tmp);
    }
    
}


void AntiThetic::ResetDimensionality(unsigned long NewDimensionality)
{
    RandomBase::ResetDimensionality(NewDimensionality);
    NextVariates.resize(NewDimensionality);
    InnerGenerator -> ResetDimensionality(NewDimensionality);
}

void AntiThetic::Reset()
{
    InnerGenerator->Reset();
    OddEven = true;
}
