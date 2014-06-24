//
//  PayOffFactory.h
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch10_factory_pattern__PayOffFactory__
#define __ch10_factory_pattern__PayOffFactory__

#include "PayOff3.h"

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include <map>
#include <string>

class PayOffFactory
{
public:
    typedef PayOff*  (*CreatePayOffFunction)(double);
    
    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
    // allows the possibility of returning a null pointer if the identity string was not found
    PayOff* CreatePayOff(std::string PayOffID, double Strike);
    ~PayOffFactory(){};
    
private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator = (const PayOffFactory&){return *this;}
};

#endif /* defined(__ch10_factory_pattern__PayOffFactory__) */
