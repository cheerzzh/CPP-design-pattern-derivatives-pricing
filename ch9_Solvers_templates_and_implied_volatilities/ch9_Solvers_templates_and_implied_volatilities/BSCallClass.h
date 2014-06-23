//
//  BSCallClass.h
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch9_Solvers_templates_and_implied_volatilities__BSCallClass__
#define __ch9_Solvers_templates_and_implied_volatilities__BSCallClass__

class BSCall
{
public:
    // initialize the class data members store parameters specify a option
    BSCall(double r_,double d_,
           double T, double Spot_,
           double Strike);
    
    //takes in the volatility and then invokes the Black–Scholes formula.
    double operator()(double Vol) const;
    
    double r;
    double d;
    double T;
    double Spot;
    double Strike;

};

#endif /* defined(__ch9_Solvers_templates_and_implied_volatilities__BSCallClass__) */
