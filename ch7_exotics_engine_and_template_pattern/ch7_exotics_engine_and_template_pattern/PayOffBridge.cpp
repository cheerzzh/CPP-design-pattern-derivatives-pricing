//
//  PayOffBridge.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
    ThePayOffPtr = innerPayOff.clone();
}


PayOffBridge::~PayOffBridge()
{
    delete ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
    if (this != &original)
    {
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    
    return *this;
}