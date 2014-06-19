//
//  PayOff1.h
//  vanilla_call
//
//  Created by cheerzzh on 21/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef PAYOFF_H //make sure only defined once
#define PAYOFF_H

class PayOff
{
public:
    enum OptionType {call, put};
    PayOff(double Strike_, OptionType TheOptionType_); // the constructor
    double operator()(double Spot) const; // main method- given a value of a spot, return the value of the payoff
    //use function objects or functors here
    //define operator() as const, this method would not modify the object
private:
    double Strike;
    OptionType TheOptionType;
};


#endif

