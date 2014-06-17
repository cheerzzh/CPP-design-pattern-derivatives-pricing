//
//  main.cpp
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 16/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 ==== Key Points
 - clone(): method of implement a virtual copy constructor
 - rule of three: copy constructor, destructor, assingment operator should all exist
 - use a wrapper class to hide memory handling
 - bridge pattern
 - new is slow
 - careful to self-assignment

 */



#include "SimpleMC6.h" // for function to do Monte Carlo Simulation on option price
#include "Vanilla3.h" // for vanilla option class
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double Expiry;
    double Strike;
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
    
    cout << "\nNumber of paths: \n";
    cin >> NumberOfPath;
    
    // build parameter class
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    // for vanilla put and call
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    
    double resultCall = SimpleMonteCarlo4(theOption, Spot, VolParam, rParam, NumberOfPath);
    
    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff,Expiry);
    theOption = thirdOption;
    
    double resultPut = SimpleMonteCarlo4(theOption, Spot, VolParam, rParam, NumberOfPath);
    
    cout <<"\nthe price are "<< resultCall<<" for the call and \n"<<resultPut<<" for the put\n";
    
    
    double call_parity = resultCall + Strike*exp(-r*Expiry);
    double put_parity = resultPut + Spot;
    
    cout << "\ntest Put-call Parity:\n\n";
    cout << "Call + K*B(r,t) == "<<call_parity <<"\n"<<"Put + S(t) == "<<put_parity<<"\n";
    
    /*
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
    */
    
    double temp;
    cin >> temp;
    
    return 0;
}


