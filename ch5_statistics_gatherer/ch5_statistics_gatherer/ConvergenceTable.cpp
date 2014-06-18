//
//  ConvergenceTable.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_):Inner(Inner_)
{
    StoppingPoint = 2;
    PathsDone = 0;
}

StatisticsMC* ConvergenceTable::clone()const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result)
{
    Inner -> DumpOneResult(result);// call method of pointed-to onject by wrapper class
    ++PathsDone;
    
    if (PathsDone == StoppingPoint)
    {
        //each time where number of paths is a multiple of 2, add result
        StoppingPoint*=2;
        std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());
        
        for (unsigned long i =0; i<thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            ResultSoFar.push_back(thisResult[i]); // update ResultSoFar
        }
    }
    return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const
{
    std::vector<std::vector<double>> tmp(ResultSoFar);
    
    // prepare the return table
    if (PathsDone*2 != StoppingPoint)
    {
        std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());
        
        for (unsigned long i=0; i<thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }
    }
    
    return tmp;
    
}
