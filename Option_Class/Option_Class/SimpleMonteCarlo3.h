//
//  SimpleMonteCarlo3.h
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __Option_Class__SimpleMonteCarlo3__
#define __Option_Class__SimpleMonteCarlo3__

#include <iostream>
#include "Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);


#endif /* defined(__Option_Class__SimpleMonteCarlo3__) */
