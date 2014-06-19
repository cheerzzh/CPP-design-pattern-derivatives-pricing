//
//  SimpleMC8.cpp
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "SimpleMC8.h"
#include <cmath>
#include "Arrays.h"


// the basic math functions should be in
// namespace std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator)
{
    // set generator's dimensionality to 1, since pricing a vanilla option is 1-D integral: only need final value of spot price
    generator.ResetDimensionality(1);
    
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0,Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r.Integral(0,Expiry)+itoCorrection);
    
    double thisSpot;
    double discounting = exp(-r.Integral(0,Expiry));
    
    // set up array first to speed up
    MJArray VariateArray(1); // store generated random normal number
    
    for (unsigned long i=0; i<NumberOfPaths; i++)
    {
        generator.GetGaussians(VariateArray);// put random number into array
        thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);
    }
    
    return;
}