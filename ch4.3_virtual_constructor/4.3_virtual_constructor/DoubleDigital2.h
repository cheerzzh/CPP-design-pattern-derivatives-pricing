//
//  DoubleDigital2.h
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 13/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_virtual_constructor__DoubleDigital2__
#define ____3_virtual_constructor__DoubleDigital2__

#include <iostream>
#include "PayOff3.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    virtual PayOff* clone() const ;
    
private:
    double LowerLevel;
    double UpperLevel;
    
    
};




#endif /* defined(____3_virtual_constructor__DoubleDigital2__) */
