//
//  PayOff3.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PayOff3.h"
#include <algorithm>


PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
    
}

double PayOffCall::operator() (double Spot) const
{
    return std::max(Spot - Strike,0.0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this); // return a copy of current payoff class
}

PayOffPut::PayOffPut(double Strike_): Strike(Strike_)
{
    
}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot,0.0);
}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(* this);
}
