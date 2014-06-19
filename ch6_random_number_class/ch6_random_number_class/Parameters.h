//
//  Parameters.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__Parameters__
#define __ch6_random_number_class__Parameters__

/*
 store parameters such as volatility, IR, general setup: jump intension...
 need to return the integral or integral sqaure over any time interval
 
 use bridge design: class Parameter point to an abstract class: ParametersInner
 */

class ParametersInner
{
public:
    ParametersInner(){}
    
    virtual ParametersInner* clone() const=0;
    virtual double Integral(double time1, double time2) const=0;
    virtual double IntegralSquare(double time1, double time2) const=0;
    virtual ~ParametersInner(){}
private:
};

class Parameters
{
public:
    Parameters(const ParametersInner& innerObject);
    Parameters(const Parameters& orignial);
    Parameters& operator=(const Parameters& original);
    virtual ~Parameters();
    
    inline double Integral(double time1, double time2) const;
    inline double IntegralSquare(double time1, double time2) const;
    double Mean(double time1, double time2)const;
    double RootMeanSquare(double time1, double time2) const;
    
private:
    ParametersInner* InnerObjectPtr; // a bridge class
};

inline double Parameters::Integral(double time1, double time2)const
{
    // call method in ParameterInner instance
    return InnerObjectPtr->Integral(time1,time2);
}

inline double Parameters::IntegralSquare(double time1, double time2)const
{
    return InnerObjectPtr->IntegralSquare(time1, time2);
}

// inheritant from ParameterInner class
class ParametersConstant:public ParametersInner
{
public:
    ParametersConstant(double constant);
    
    virtual ParametersInner* clone() const;
    virtual double Integral(double time1,double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
    
private:
    double Constant;
    double ConstantSquare;
};

#endif /* defined(__ch6_random_number_class__Parameters__) */
