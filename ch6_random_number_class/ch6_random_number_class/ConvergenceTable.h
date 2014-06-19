//
//  ConvergenceTable.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__ConvergenceTable__
#define __ch6_random_number_class__ConvergenceTable__

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


#endif /* defined(__ch6_random_number_class__ConvergenceTable__) */
