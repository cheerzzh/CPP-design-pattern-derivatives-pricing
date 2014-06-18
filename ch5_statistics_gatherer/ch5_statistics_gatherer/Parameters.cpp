//
//  Parameters.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Parameters.h"

//==== for Parameters class

Parameters::Parameters(const ParametersInner& InnerObject)
{
    InnerObjectPtr = InnerObject.clone();
}

Parameters::Parameters(const Parameters& original)
{
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

//return a refernece, not a copy
Parameters& Parameters::operator=(const Parameters &original)
{
    if (this != &original)
    {
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    
    return *this;
}

Parameters::~Parameters()
{
    delete  InnerObjectPtr;
}


/*
 return average value of the parameter between two time
 */
double Parameters::Mean(double time1, double time2) const
{
    // calaulate integral over time interval
    double total = Integral(time1, time2);
    return total/(time2-time1); // get mean
}

/*
 
 */
double Parameters::RootMeanSquare(double time1, double time2) const
{
    double total = IntegralSquare(time1, time2);
    return total/(time1-time2);
}

//==== for ParametersConstant class
ParametersConstant::ParametersConstant(double constant)
{
    this->Constant = constant;
    this->ConstantSquare = Constant*Constant;
    
}

ParametersInner* ParametersConstant::clone()const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2)const
{
    return (time2-time1)*Constant;
    
}

double ParametersConstant::IntegralSquare(double time1, double time2)const
{
    return (time2-time1)*ConstantSquare;
}
