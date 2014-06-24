//
//  PayOffFactory.cpp
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include "PayOffFactory.h"
#include <iostream>
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId,
                                   CreatePayOffFunction CreatorFunction)
{
    // add one map: sting <-> payoff
    TheCreatorFunctions.insert(pair<string,CreatePayOffFunction>
                               (PayOffId,CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId,
                                    double Strike)
{
    map<string, CreatePayOffFunction>::const_iterator
    i = TheCreatorFunctions.find(PayOffId); // serach through the map space to find the corresponding
    if  (i == TheCreatorFunctions.end())
    {
        std::cout << PayOffId
        << " is an unknown payoff" << std::endl;
        return NULL;
    }
    // a pair contains two public data member: first and second
    return (i->second)(Strike); // return an payoff object
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}


