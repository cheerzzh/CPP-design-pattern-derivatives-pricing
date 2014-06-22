//
//  PathDependentAsian.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__PathDependentAsian__
#define __ch7_exotics_engine_and_template_pattern__PathDependentAsian__

#include "PathDependent.h"
#include "PayOffBridge.h"


class PathDependentAsian : public PathDependent
{
public:
    PathDependentAsian(const MJArray& LookAtTimes_,
                       double DeliveryTime_,
                       const PayOffBridge& ThePayOff_);
    
    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual MJArray PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const; // store the cash flow in a vector of CashFlow by pass by reference
    virtual ~PathDependentAsian(){}
    virtual PathDependent* clone() const;
    
private:
    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
};

#endif /* defined(__ch7_exotics_engine_and_template_pattern__PathDependentAsian__) */
