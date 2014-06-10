//
//  DoubleDigital.cpp
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "DoubleDigital.h"

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
