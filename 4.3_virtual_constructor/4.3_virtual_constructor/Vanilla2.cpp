//
//  Vanilla2.cpp
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 13/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Vanilla2.h"

VanillaOption::VanillaOption(const PayOff& ThePayOff_,
                             double Expiry_): Expiry(Expiry_) // set Expiry
{
    ThePayOffPtr = ThePayOff_.clone(); // return a pointer point to a copy of the payoff instance
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return (*ThePayOffPtr)(Spot); // use () method from payoff instance
}

VanillaOption::VanillaOption(const VanillaOption& original) // a copy constructor
{
    Expiry = original.Expiry;
    ThePayOffPtr = original.ThePayOffPtr -> clone(); // make a copy of payoff instance again
}


/* 
 overloading the asignment operator "=",
 
 */
VanillaOption& VanillaOption::operator = (const VanillaOption& original) // copy the instance
{
    if(this != &original) // check against self-assignnment
    {
        Expiry = original.Expiry;
        delete ThePayOffPtr; // release the memor, otherwisw memory leaks
        ThePayOffPtr = original.ThePayOffPtr -> clone();
    }
    return *this; // return a vanilla option class pointer
}

VanillaOption::~VanillaOption() // finalizer
{
    delete ThePayOffPtr; // release the memory pointed by payoff pointer
}


