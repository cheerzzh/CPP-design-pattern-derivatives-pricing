//
//  SimpleMC4.h
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 13/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef ____3_virtual_constructor__SimpleMC4__
#define ____3_virtual_constructor__SimpleMC4__

#include "Vanilla2.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif /* defined(____3_virtual_constructor__SimpleMC4__) */