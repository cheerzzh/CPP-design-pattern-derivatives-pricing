//
//  Vanilla3.h
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 16/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_PayOffBridge__Vanilla3__
#define ____3_PayOffBridge__Vanilla3__

#include "PayOffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_,double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
    
private:
    double Expiry;
    PayOffBridge ThePayOff;
};


#endif /* defined(____3_PayOffBridge__Vanilla3__) */
