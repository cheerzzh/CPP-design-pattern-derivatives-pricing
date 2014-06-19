//
//  SimpleMC8.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__SimpleMC8__
#define __ch6_random_number_class__SimpleMC8__

#include "Vanilla3.h"
#include "Parameters.h"
#include "Random2.h"
#include "MCStatistics.h"

// take random number generator in as non-const reference
// since generate number will change generator object

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator);


#endif /* defined(__ch6_random_number_class__SimpleMC8__) */
