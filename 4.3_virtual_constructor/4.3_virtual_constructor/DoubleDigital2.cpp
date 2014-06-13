//
//  DoubleDigital2.cpp
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 13/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "DoubleDigital2.h"
#include <algorithm>

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double Upperlevel_)
: LowerLevel(LowerLevel_), UpperLevel(Upperlevel_)
{
    
}

double PayOffDoubleDigital::operator()(double Spot) const
{
    if (Spot <= LowerLevel)
        return 0;
    if (Spot >= UpperLevel)
        return 0;
    
    return 1;
}

PayOff* PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}