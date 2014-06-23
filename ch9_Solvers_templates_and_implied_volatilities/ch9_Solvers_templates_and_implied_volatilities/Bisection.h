//
//  Bisection.h
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch9_Solvers_templates_and_implied_volatilities__Bisection__
#define __ch9_Solvers_templates_and_implied_volatilities__Bisection__

#include <cmath>

template<class T> // class T is a function object, T(args) behave like a normal function
double Bisection(double Target,
                 double Low,
                 double High,
                 double Tolerance,
                 T TheFunction)
{
    double x = 0.5 * (Low + High);
    double y = TheFunction(x); // compute function value at mid
    
    do
    {
        if (y < Target)
            Low = x;
        
        if (y > Target)
            High = x;
        x = 0.5*(Low + High);
        
        y = TheFunction(x);
    }
    while ((fabs(y-Target)>Tolerance));
    
    return x;
}

#endif /* defined(__ch9_Solvers_templates_and_implied_volatilities__Bisection__) */
