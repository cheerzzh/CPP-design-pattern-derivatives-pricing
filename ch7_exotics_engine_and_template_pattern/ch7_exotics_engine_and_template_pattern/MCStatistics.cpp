//
//  MCStatistics.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "MCStatistics.h"

using namespace std;

StatisticsMean::StatisticsMean(): RunningSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

// called only once per simulation
vector<vector<double>> StatisticsMean::GetResultsSoFar()const
{
    vector<vector<double>> Results(1);
    
    Results[0].resize(1); // first vector length = 1
    Results[0][0]=RunningSum/PathsDone; // store mean
    
    return Results;
}

StatisticsMC* StatisticsMean::clone()const
{
    return new StatisticsMean(*this);
}
