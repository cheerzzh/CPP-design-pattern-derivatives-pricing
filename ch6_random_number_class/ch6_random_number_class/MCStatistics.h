//
//  MCStatistics.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__MCStatistics__
#define __ch6_random_number_class__MCStatistics__

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC(){}
    
    virtual void DumpOneResult(double result)=0; // a pure virtual function
    virtual std::vector<std::vector<double>> GetResultsSoFar()const=0;
    virtual StatisticsMC* clone()const=0;// possibility of virtual copy construction
    virtual ~StatisticsMC(){}//virtual destructor
    
private:
};


/*
 inherited from StatisticsMC, return mean of simulation
 */
class StatisticsMean:public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone() const;
    
private:
    double RunningSum;
    unsigned long PathsDone;
};

#endif /* defined(__ch6_random_number_class__MCStatistics__) */

