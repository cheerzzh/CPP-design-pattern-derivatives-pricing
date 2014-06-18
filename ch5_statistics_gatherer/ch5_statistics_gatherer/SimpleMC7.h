//
//  SimpleMC7.h
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch5_statistics_gatherer__SimpleMC7__
#define __ch5_statistics_gatherer__SimpleMC7__

#include "Vanilla3.h" // use vanilla option class
#include "Parameters.h" // parameter class for IR and volatility
#include "MCStatistics.h"// store result from MC simulation paths

// previous return double, since now stored in gatherer, no return required
void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer);
// StatisticsMC is passed by reference and not constant
//

#endif /* defined(__ch5_statistics_gatherer__SimpleMC7__) */
