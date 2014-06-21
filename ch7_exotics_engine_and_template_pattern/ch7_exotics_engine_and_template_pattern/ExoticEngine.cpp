//
//  ExoticEngine.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "ExoticEngine.h"
#include <cmath>


ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_): TheProduct(TheProduct_), r(r_),Discounts(TheProduct_->PossibleCashFlowTimes())
{
    // array Discounts first store time, then compute the discount factor first
    for (unsigned long i =0; i<Discounts.size(); i++)
    {
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
    }
    
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC &TheGatherer, unsigned long NumberOfPaths)
{
    MJArray SpotValues(TheProduct-> GetLookAtTimes().size());
    
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
    double thisValue;
    
    for (unsigned long i=0; i<NumberOfPaths; i++)
    {
        GetOnePath(SpotValues); // simulation one path, possible spot stored in array SpotValue
        thisValue = DoOnePath(SpotValues); // calcuate the PV of payoff cashflow
        TheGatherer.DumpOneResult(thisValue);
    }

    return;
}

double ExoticEngine::DoOnePath(const MJArray &SpotValues) const
{
    unsigned long NumberFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
    
    double Value = 0.0;
    
    // perform discounting om cash flows
    for (unsigned long i=0; i<NumberFlows; i++)
    {
        Value += TheseCashFlows[i].Amount * Discounts[TheseCashFlows[i].TimeIndex];
    }
    
    return Value;
}


