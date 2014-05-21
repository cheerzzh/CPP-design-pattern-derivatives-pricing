//
//  main.cpp
//  vanilla_call
//
//  Created by cheerzzh on 21/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

//require Random1.cpp
// simple straightforward procedural

#include"Random1.h"
#include <iostream>
#include <cmath>
using namespace std;

//function doing the MC simulation
double SimpleMonteCarlo1(double Expiry,
                         double Strike,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPath)
{
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoVorrelation = -0.5 * variance;
    
    double movedSpot = Spot*exp(r*Expiry + itoVorrelation);//compute first to recude call exp()
    double thisSpot;
    double runningSum = 0;
    
    for (unsigned long i =0; i< NumberOfPath; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff>0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    
    double mean = runningSum / NumberOfPath;
    mean *= exp(-r* Expiry);
    return mean;
}

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPath;
    
    //read in parameters
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    
    cout << "\nEnter Strike\n";
    cin >> Strike;
    
    cout << "\nEnter spot\n";
    cin >> Spot;
    
    cout << "\nEnter vol\n";
    cin >> Vol;
    
    cout << "\nEnter r\n";
    cin >> r;
    
    cout << "\n Number of paths\n";
    cin >> NumberOfPath;
    
    double result = SimpleMonteCarlo1(Expiry,
                                      Strike,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPath);
    cout << "the price is "<< result << "\n";
    
    double tmp;
    cin >>tmp;

    return 0;

}






