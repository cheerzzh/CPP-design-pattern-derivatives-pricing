//
//  ExoticEngine.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__ExoticEngine__
#define __ch7_exotics_engine_and_template_pattern__ExoticEngine__


// a base class for pricing engine

#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include <vector>
#include "MCStatistics.h"

// GetOnePath() can defined under different model

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);
    
    // pure virtual method-> defined in inherited class to adopt various stochastic process and model
    virtual void GetOnePath(MJArray& SpotValues)=0; // return array of spot by storing them into a array
    void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
    virtual ~ExoticEngine(){}
    double DoOnePath(const MJArray& SpotValues) const; // get the sum of PV of payoff cashflows
    
private:
    Wrapper<PathDependent> TheProduct; // to store the option product
    Parameters r; // store IR
    MJArray Discounts; // store the discount factors
    mutable std::vector<CashFlow> TheseCashFlows; // use "mutable", it can be changed even in const member functions
};

#endif /* defined(__ch7_exotics_engine_and_template_pattern__ExoticEngine__) */
