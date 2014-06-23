//
//  NewtonRaphso.h
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch9_Solvers_templates_and_implied_volatilities__NewtonRaphso__
#define __ch9_Solvers_templates_and_implied_volatilities__NewtonRaphso__

#include <cmath>

//three template parameters
template<class T, double (T::*Value)(double) const,double (T::*Derivative)(double) const >
    double NewtonRaphson(double Target,
                     double Start,
                     double Tolerance,
                     const T& TheObject)
{
    double y = (TheObject.*Value)(Start); // pass initial guess to function
    double x=Start;
    
    while ( fabs(y - Target) > Tolerance )
    {
        double d = (TheObject.*Derivative)(x);
        x+= (Target-y)/d;
        y = (TheObject.*Value)(x); // check the target function value
    }
    
    return x;
    
}

#endif /* defined(__ch9_Solvers_templates_and_implied_volatilities__NewtonRaphso__) */
