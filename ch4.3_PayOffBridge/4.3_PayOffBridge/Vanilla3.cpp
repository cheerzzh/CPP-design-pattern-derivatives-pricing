//
//  Vanilla3.cpp
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 16/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Vanilla3.h"

// all the work ha been done by payoff bridge class
VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_)
: ThePayOff(ThePayOff_),Expiry(Expiry_)
{
    
}


double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return ThePayOff(Spot);
}


