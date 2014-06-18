//
//  Vanilla3.h
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch5_statistics_gatherer__Vanilla3__
#define __ch5_statistics_gatherer__Vanilla3__

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

#endif /* defined(__ch5_statistics_gatherer__Vanilla3__) */
