//
//  DoubleDigital.h
//  Payoff_class_with_inheritance
//
//  Created by cheerzzh on 8/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __Payoff_class_with_inheritance__DoubleDigital__
#define __Payoff_class_with_inheritance__DoubleDigital__

#include <iostream>
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    
private:
    double LowerLevel;
    double UpperLevel;
    
    
};

#endif /* defined(__Payoff_class_with_inheritance__DoubleDigital__) */
