//
//  Vanilla2.h
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 13/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_virtual_constructor__Vanilla2__
#define ____3_virtual_constructor__Vanilla2__

#include <iostream>
#include "PayOff3.h"

class VanillaOption
{
public:
    VanillaOption(const PayOff& ThePayOff_, double Expiry); //
    VanillaOption(const VanillaOption& original); // copy constructor to ensure a deep copy
    VanillaOption& operator= (const VanillaOption& original); // overloading assignment operator "=" to copy option instance
    ~VanillaOption();
    
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
    
private:
    double Expiry;
    PayOff* ThePayOffPtr;
};

#endif /* defined(____3_virtual_constructor__Vanilla2__) */
