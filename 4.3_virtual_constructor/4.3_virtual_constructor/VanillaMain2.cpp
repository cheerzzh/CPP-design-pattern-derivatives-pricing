//
//  main.cpp
//  4.3_virtual_constructor
//
//  Created by cheerzzh on 12/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "SimpleMC4.h" // for function to do Monte Carlo Simulation on option price
#include "DoubleDigital2.h" // for payoff class on double digital option
#include "Vanilla2.h" // for vanilla option class
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPath;
    
    //read in parameters
    cout << "\nEnter expiry: \n";
    cin >> Expiry;
    
    cout << "\nEnter spot: \n";
    cin >> Spot;
    
    cout << "\nEnter strike: \n";
    cin >> Strike;

    cout << "\nEnter vol: \n";
    cin >> Vol;
    
    cout << "\nEnter r: \n";
    cin >> r;
    
    cout << "\nEnter low barrier\n";
    cin >> Low;
    
    cout << "\nEnter up barrier\n";
    cin >> Up;
    
    cout << "\nNumber of paths: \n";
    cin >> NumberOfPath;
    
    
    // for vanilla put and call
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    
    double resultCall = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPath);
    
    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff,Expiry);
    theOption = thirdOption;
    
    double resultPut = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPath);
    
    cout <<"\nthe price are "<< resultCall<<" for the call and \n"<<resultPut<<" for the put\n";
    

    double call_parity = resultCall + Strike*exp(-r*Expiry);
    double put_parity = resultPut + Spot;
    
    cout << "\ntest Put-call Parity:\n\n";
    cout << "Call + K*B(r,t) == "<<call_parity <<"\n"<<"Put + S(t) == "<<put_parity<<"\n";
    
    
    // for barrier option
    
    PayOffDoubleDigital doublePayOff(Low,Up); // prepare payoff object
    VanillaOption doubleOption(thePayOff,Expiry); // prepare option object
    theOption = doubleOption;
    
    double resultDouble = SimpleMonteCarlo3(theOption,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPath);
    
    cout << "\nThe price for double digital with low barrier = "<<Low << " and up barrier = "<<Up<<" is "<< resultDouble<<"\n";
    
    double temp;
    cin >> temp;
    
    return 0;
}


// sample result
/*
 
 Enter expiry:
 1
 
 Enter spot:
 100
 
 Enter strike:
 120
 
 Enter vol:
 0.4
 
 Enter r:
 0.05
 
 Enter low barrier
 100
 
 Enter up barrier
 120
 
 Number of paths:
 1000000
 
 the price are 10.8395 for the call and
 24.9681 for the put
 
 test Put-call Parity:
 
 Call + K*B(r,t) == 124.987
 Put + S(t) == 124.968
 
 the price for double digital with low barrier = 100 and up barrier = 120 is 10.8124
 
 */
