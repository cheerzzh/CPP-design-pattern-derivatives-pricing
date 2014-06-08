//
//  SimpleMC2.h
//  Payoff_class_with_inheritance
//
//  Created by cheerzzh on 7/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __Payoff_class_with_inheritance__SimpleMC2__
#define __Payoff_class_with_inheritance__SimpleMC2__

#include <iostream>
#include "PayOff2.h"
double SimpleMonteCarlo2(const PayOff& thePayOff, // use PayOff class, strike is hidden inside the Payoff object
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPath);




#endif /* defined(__Payoff_class_with_inheritance__SimpleMC2__) */
