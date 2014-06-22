//
//  ConvergenceTable.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 22/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__ConvergenceTable__
#define __ch7_exotics_engine_and_template_pattern__ConvergenceTable__

#include "MCStatistics.h"
#include "Wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
    // constructor, take in a wrapper class which point to a StatisticMC object
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    
private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};


#endif /* defined(__ch7_exotics_engine_and_template_pattern__ConvergenceTable__) */
