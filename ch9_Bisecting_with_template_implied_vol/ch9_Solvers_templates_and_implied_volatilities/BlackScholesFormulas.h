//
//  BlackScholesFormulas.h
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch9_Solvers_templates_and_implied_volatilities__BlackScholesFormulas__
#define __ch9_Solvers_templates_and_implied_volatilities__BlackScholesFormulas__

double BlackScholesCall( double Spot,
                        double Strike,
                        double r,
                        double d,
                        double Vol,
                        double Expiry);


double BlackScholesPut( double Spot,
                       double Strike,
                       double r,
                       double d,
                       double Vol,
                       double Expiry);

double BlackScholesDigitalCall(double Spot,
                               double Strike,
                               double r,
                               double d,
                               double Vol,
                               double Expiry);


double BlackScholesCallVega( double Spot,
                            double Strike,
                            double r,
                            double d,
                            double Vol,
                            double Expiry);

#endif /* defined(__ch9_Solvers_templates_and_implied_volatilities__BlackScholesFormulas__) */
