//
//  PayOffBridge.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__PayOffBridge__
#define __ch6_random_number_class__PayOffBridge__

#include "PayOff3.h"

class PayOffBridge
{
public:
    
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    
    PayOff* ThePayOffPtr;
    
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator ()(Spot);
}


#endif /* defined(__ch6_random_number_class__PayOffBridge__) */
