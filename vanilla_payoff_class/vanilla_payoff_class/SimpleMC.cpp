//
//  SimpleMC.cpp
//  vanilla_payoff_class
//
//  Created by cheerzzh on 21/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

//the basic math functions should be in
#if !defined(_MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo2(const PayOff& thePayOff, // use PayOff class, strike is hidden inside the Payoff object
                  double Expiry,
                  double Spot,
                  double Vol,
                  double r,
                  unsigned long NumberOfPath)
{
    double variance = Vol*Vol*Expiry;
    double rootVariacne = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot * exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    
    for(unsigned long i =0; i<NumberOfPath;i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariacne*thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPath;
    mean *= exp(-r*Expiry);
    return mean;
}


