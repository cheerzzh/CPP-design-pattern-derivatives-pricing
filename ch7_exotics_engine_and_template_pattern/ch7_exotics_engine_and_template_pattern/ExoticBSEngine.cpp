//
//  ExoticBSEngine.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "ExoticBSEngine.h"
#include <cmath>

void ExoticBSEngine::GetOnePath(MJArray &SpotValues)
{
    TheGenerator -> GetGaussians(Variates); // get normal
    
    double CurrentLogSpot = LogSpot;
    
    for (unsigned long j=0; j<NumberOfTimes; j++)
    {
        // according to the BS model
        // logSt = logS(t-1) + drift + sqrt(variacne)*z
        CurrentLogSpot += Drifts[j];
        CurrentLogSpot += StandardDeviations[j]*Variates[j];
        SpotValues[j] = exp(CurrentLogSpot); // raise to exp, get spot value of one path at various time points
    }
    return;

}

// pass in a wrapper object on RandomBase, so that we can plug in any random number generator at will
//
ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                               const Parameters& R_,
                               const Parameters& D_,
                               const Parameters& Vol_,
                               const Wrapper<RandomBase>& TheGenerator_,
                               double Spot_):
                                ExoticEngine(TheProduct_,R_),
                                TheGenerator(TheGenerator_)
{
    MJArray Times(TheProduct_ ->GetLookAtTimes());
    NumberOfTimes = Times.size(); // time points needed within one simulated path
    
    TheGenerator -> ResetDimensionality(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);
    
    // pre compute the drift term and variacne within each time steps
    double Variance = Vol_.IntegralSquare(0, Times[0]); // first time point
    // compute drift term within first time point
    Drifts[0] = R_.Integral(0, Times[0]) - D_.Integral(0, Times[0]) - 0.5*Variance;
    StandardDeviations[0] = sqrt(Variance);
    
    for (unsigned long j=1; j<NumberOfTimes; j++)
    {
        double thisVariance = Vol_.IntegralSquare(Times[j-1], Times[j]);
        Drifts[j] = R_.Integral(Times[j-1],Times[j])
                    - D_.Integral(Times[j-1],Times[j])
                    - 0.5 * thisVariance;
        StandardDeviations[j] = sqrt(thisVariance);

    }
    
    LogSpot = log(Spot_); // logS(0)
    Variates.resize(NumberOfTimes);

}


