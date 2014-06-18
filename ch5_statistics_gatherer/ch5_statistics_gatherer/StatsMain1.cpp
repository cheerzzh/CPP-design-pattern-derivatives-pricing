//
//  StatsMain1.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 uses source files
 MCStatistics.cpp,
 Parameters.cpp,
 PayOff3.cpp,
 PayOffBridge.cpp,
 Random1.cpp,
 SimpleMC7.cpp,
 Vanilla3.cpp,
 */

#include "SimpleMC7.h"
#include <iostream>
#include "Vanilla3.h"
#include "MCStatistics.h"

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    
    cout << "\nEnter expiry:\n";
    cin >> Expiry;
    
    cout << "\nStrike:\n";
    cin >> Strike;
    
    cout << "\nEnter spot:\n";
    cin >> Spot;
    
    cout << "\nEnter vol:\n";
    cin >> Vol;
    
    cout << "\nr:\n";
    cin >> r;
    
    cout << "\nNumber of paths:\n";
    cin >> NumberOfPaths;
    
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    StatisticsMean gatherer;
    
    SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);
    
    vector<vector<double> > results = gatherer.GetResultsSoFar();
    
    cout <<"\nFor the call price the results are \n";
    
    // loop over the vectors of vectors to display results
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
        cout << "\n";
    }
    
    double tmp;
    cin >> tmp;


    return 0;
}