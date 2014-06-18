//
//  ConvergenceTable.h
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch5_statistics_gatherer__ConvergenceTable__
#define __ch5_statistics_gatherer__ConvergenceTable__

/*
 
 - examine the SD of simulation
 - convergence table
 - this class contain a statistics gatherer to create a convergence table
 
 === decorator pattern ======
 - inherit ConvergenceTable from MCStatistics: from outside, looks like any other statistics gatherer
 - and has a wrapper of an MCStatistics object as a data member: can make table for any statistics
 - no need to write copy constructor, destructor or assignment operator, since dynamic memory allocation is handled by Wrapper template class
 
 */

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


#endif /* defined(__ch5_statistics_gatherer__ConvergenceTable__) */
