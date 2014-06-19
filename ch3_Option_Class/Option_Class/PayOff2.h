//
//  PayOff2.h
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __Option_Class__PayOff2__
#define __Option_Class__PayOff2__

#include <iostream>


class PayOff //base class
{
public:
    PayOff(){};
    // pure virtual function -> need not to be defined in base class
    // must be defined in a inherited class
    // the base class in incomplete
    virtual double operator()(double Spot) const = 0; //given spot,return payoff
    virtual ~PayOff(){}
    
private:
    
};


class PayOffCall: public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const; //overloading () to return payoff
    virtual ~PayOffCall(){}
    
private:
    double Strike;
};


class PayOffPut: public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    
private:
    double Strike;
    
};
#endif /* defined(__Option_Class__PayOff2__) */
