//
//  PayOffBridge.h
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 16/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_PayOffBridge__PayOffBridge__
#define ____3_PayOffBridge__PayOffBridge__


#include "PayOff3.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original); // copy constructor
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr -> operator()(Spot); // call the method in PayOff class to get the payoff
}


#endif /* defined(____3_PayOffBridge__PayOffBridge__) */
