//
//  main.cpp
//  vanilla_payoff_class
//
//  Created by cheerzzh on 21/5/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//
#include"SimpleMC.h"
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
    
    PayOff callPayOff(Strike, PayOff::call);//PayOff object
    PayOff putPayOff(Strike,PayOff::put);
    
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
    cout <<"the price are "<< resultCall<<"for the call and "<<resultput<<" for the put\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;


}