//
//  EquityFXMain.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 uses source files
 AntiThetic.cpp
 Arrays.cpp,
 ConvergenceTable.cpp,
 ExoticBSEngine.cpp
 ExoticEngine.cpp
 MCStatistics.cpp
 Normals.cpp
 Parameters.cpp,
 ParkMiller.cpp,
 PathDependent.cpp
 PathDependentAsian.cpp
 PayOff3.cpp,
 PayOffBridge.cpp,
 Random2.cpp,
 */

#include "Parameters.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"
#include "ParkMiller.h"
#include "PayOff3.h"
#include <iostream>
using namespace std;

int main()
{
    
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberOfPaths;
    unsigned NumberOfDates; // averaging frequency in Asian option
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    
    cout << "\nStrike\n";
    cin >> Strike;
    
    cout << "\nEnter spot\n";
    cin >> Spot;
    
    cout << "\nEnter vol\n";
    cin >> Vol;
    
    cout << "\nr\n";
    cin >> r;
    
    cout << "\nd\n";
    cin >> d;
    
    cout << "Number of dates\n";
    cin >> NumberOfDates;
    
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    
    PayOffCall thePayOff(Strike);
    
    // compute time point 0~expiry, evenly splited
    MJArray times(NumberOfDates);
    for (unsigned long i=0; i < NumberOfDates; i++)
        times[i] = (i+1.0)*Expiry/NumberOfDates;
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    PathDependentAsian theOption(times, Expiry, thePayOff);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(NumberOfDates);
    
    AntiThetic GenTwo(generator);
    
    ExoticBSEngine theEngine(theOption, rParam, dParam,
                             VolParam, GenTwo, Spot);
    
    theEngine.DoSimulation(gathererTwo, NumberOfPaths);
    
    vector<vector<double> > results =
    gathererTwo.GetResultsSoFar();
    
    cout <<"\nFor the Asian call price the results are \n";
    
    {
        for (unsigned long i=0; i < results.size(); i++)
        {
            for (unsigned long j=0; j < results[i].size(); j++)
                cout << results[i][j] << " ";
            cout << "\n";
        }
    }
    
    double tmp;
    cin >> tmp;
    
    
    
    return 0;
}





