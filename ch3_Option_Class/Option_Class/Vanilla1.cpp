//
//  Vanilla1\.cpp
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Vanilla1.h"

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_)
:ThePayOff(ThePayOff_), Expiry(Expiry_)
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
