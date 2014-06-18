//
//  PayOff3.h
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch5_statistics_gatherer__PayOff3__
#define __ch5_statistics_gatherer__PayOff3__

class PayOff
{
public:
    PayOff(){}
    
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const = 0; // virtual copy constructor
    
private:
};


class PayOffCall: public PayOff
{
public:
    PayOffCall(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
    
private:
    double Strike;
};

class PayOffPut: public PayOff
{
public:
    PayOffPut(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;
    
private:
    double Strike;
};


#endif /* defined(__ch5_statistics_gatherer__PayOff3__) */
