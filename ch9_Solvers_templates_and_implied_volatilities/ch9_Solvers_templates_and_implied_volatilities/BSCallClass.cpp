//
//  BSCallClass.cpp
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "BSCallClass.h"
#include "BlackScholesFormulas.h" // for directly computing the option price using BS formula


BSCall::BSCall(double r_, double d_,
               double T_, double Spot_,
               double Strike_)
:
r(r_),d(d_),
T(T_),Spot(Spot_),
Strike(Strike_)
{}

double BSCall::operator()(double Vol)const
{
    return BlackScholesCall(Spot,Strike,r,d,Vol,T);
}


