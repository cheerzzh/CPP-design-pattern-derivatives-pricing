//
//  main.cpp
//  Payoff_class_with_inheritance
//
//  Created by cheerzzh on 23/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include"SimpleMC2.h"
#include "DoubleDigital.h"
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
    double Low, Up;
    unsigned long NumberOfPath;
    
    //read in parameters
    cout << "\nEnter expiry: \n";
    cin >> Expiry;
    
    cout << "\nEnter Strike: \n";
    cin >> Strike;
    
    cout << "\nEnter spot: \n";
    cin >> Spot;
    
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
    
    PayOffCall callPayOff(Strike);//PayOff object
    PayOffPut putPayOff(Strike);
    PayOffDoubleDigital doubleDigitalPayoff(Low, Up);
    
    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPath);
    
    double resultput = SimpleMonteCarlo2(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPath);
    
    double resultDouble = SimpleMonteCarlo2(doubleDigitalPayoff,
                                           Expiry,
                                           Spot,
                                           Vol,
                                           r,
                                           NumberOfPath);
    
    cout <<"\nthe price are "<< resultCall<<" for the call and \n"<<resultput<<" for the put\n";
    
    cout << "\n the price for double digital with low barrier = "<<Low << " and up barrier = "<<Up<<" is "<< resultDouble<<"\n";
    
    double call_parity = resultCall + Strike*exp(-r*Expiry);
    double put_parity = resultput + Spot;
    
    cout << "\ntest Put-call Parity:\n\n";
    cout << "Call + K*B(r,t) == "<<call_parity <<"\n"<<"Put + S(t) == "<<put_parity<<"\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;
}


// sample reuslt
/*
 
 Number of Paths: 10000000
 Underlying:      100
 Lower Strike:    100
 Upper Strike:    120
 Risk-Free Rate:  0.05
 Volatility:      0.2
 Maturity:        1
 Options Price:   0.32009
 
 ===================================
 Enter expiry:
 1
 
 Enter Strike:
 100
 
 Enter spot:
 100
 
 Enter vol:
 0.2
 
 Enter r:
 0.05
 
 Enter low barrier
 100
 
 Enter up barrier
 120
 
 Number of paths:
 10000000
 
 the price are 10.4553 for the call and
 5.57388 for the put
 
 the price for double digital with low barrier = 100 and up barrier = 120 is 0.319894
 
 test Put-call Parity:
 
 Call + K*B(r,t) == 105.578
 Put + S(t) == 105.574
 
 ===================
 
 Enter expiry:
 1
 
 Enter Strike:
 100
 
 Enter spot:
 100
 
 Enter vol:
 0.2
 
 Enter r:
 0.05
 
 Enter low barrier
 100
 
 Enter up barrier
 120
 
 Number of paths:
 100000000
 
 the price are 10.4522 for the call and
 5.57409 for the put
 
 the price for double digital with low barrier = 100 and up barrier = 120 is 0.320055
 
 test Put-call Parity:
 
 Call + K*B(r,t) == 105.575
 Put + S(t) == 105.574
 
 */