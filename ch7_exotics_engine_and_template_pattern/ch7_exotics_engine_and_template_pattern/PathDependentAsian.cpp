//
//  PathDependentAsian.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PathDependentAsian.h"

PathDependentAsian::PathDependentAsian(const MJArray&
                                       LookAtTimes_,
                                       double DeliveryTime_,
                                       const PayOffBridge&ThePayOff_)
:
PathDependent(LookAtTimes_),
DeliveryTime(DeliveryTime_),
ThePayOff(ThePayOff_),
NumberOfTimes(LookAtTimes_.size())
{ }


unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
    return 1UL; // since Asian option, can return at most 1 cash flow, which is at terminal time
}

MJArray PathDependentAsian::PossibleCashFlowTimes() const
{
    MJArray tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}


unsigned long PathDependentAsian::CashFlows(const MJArray&
                                            SpotValues,
                                            std::vector<CashFlow>& GeneratedFlows) const
{
    // averaging, def of Asian option
    double sum = SpotValues.sum();
    double mean = sum/NumberOfTimes;
    
    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount=  ThePayOff(mean);
    
    return  1UL;
    
}


PathDependent* PathDependentAsian::clone() const
{
    return new PathDependentAsian(*this);
}


