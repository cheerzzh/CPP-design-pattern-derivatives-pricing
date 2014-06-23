//
//  BSCallTwo.h
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch9_Solvers_templates_and_implied_volatilities__BSCallTwo__
#define __ch9_Solvers_templates_and_implied_volatilities__BSCallTwo__

//class will therefore have to support pricing as a function of volatility and the vega as a function of volatility.

class BSCallTwo
{
public:
    BSCallTwo(double r_, double d_,
              double T, double Spot_,
              double Strike_);
    
    double Price(double Vol) const;
    double Vega(double Vol) const;
    
private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
};

#endif /* defined(__ch9_Solvers_templates_and_implied_volatilities__BSCallTwo__) */
