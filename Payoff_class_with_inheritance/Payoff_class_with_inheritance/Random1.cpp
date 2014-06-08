//
//  Random1.cpp
//  Payoff_class_with_inheritance
//
//  Created by cheerzzh on 7/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

//Random1.cpp

#include "Random1.h"
#include <cstdlib>
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif



double GetOneGaussianBySummation()
{
	double result = 0;
    
	for(unsigned long j=0;j<12;j++)
		result += rand()/static_cast<double>(RAND_MAX);
    
	result -= 6.0;
    
	return result;
}




double GetOneGaussianByBoxMuller()
{
	double result;
	double x, y;
	double sizeSquared;
    
	do
	{
		x = 2.0 * rand()/static_cast<double>(RAND_MAX)-1;
		y = 2.0 * rand()/static_cast<double>(RAND_MAX)-1;
		sizeSquared = x*x + y*y;
	}
	while (sizeSquared >= 1.0);
	result = x*sqrt(-2*log(sizeSquared)/sizeSquared);
    
	return result;
}
















