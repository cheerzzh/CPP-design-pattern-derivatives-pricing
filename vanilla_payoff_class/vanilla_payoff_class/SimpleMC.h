//
//  SimpleMC.h
//  vanilla_payoff_class
//
//  Created by cheerzzh on 21/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "PayOff1.h"


double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPath);

#endif



