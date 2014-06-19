//
//  Vanilla3.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__Vanilla3__
#define __ch6_random_number_class__Vanilla3__

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

#endif /* defined(__ch6_random_number_class__Vanilla3__) */
