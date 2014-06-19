//
//  SimpleMC6.h
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 17/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_PayOffBridge__SimpleMC6__
#define ____3_PayOffBridge__SimpleMC6__

#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonteCarlo4(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths);

#endif /* defined(____3_PayOffBridge__SimpleMC6__) */
