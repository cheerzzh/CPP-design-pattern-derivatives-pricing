//
//  main.cpp
//  ch9_Solvers_templates_and_implied_volatilities
//
//  Created by cheerzzh on 23/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/* Needs
 BlackScholesFormulas.cpp
 BSCallClass.cpp
 Normals.cpp
 BSCallTwo.cpp
 */

#include <iostream>
#include "Bisection.h"
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"
#include "NewtonRaphso.h"
#include "BSCallTwo.h"
#include <cmath>

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    
    cout << "\nStrike\n";
    cin >> Strike;
    
    cout << "\nEnter spot\n";
    cin >> Spot;
    
    cout << "\nEnter price\n";
    cin >> Price;
    
    cout << "\nr\n";
    cin >> r;
    
    cout << "\nd\n";
    cin >> d;
    
    double low,high;
    
    cout << "\nlower guess\n";
    cin >> low;
    cout << "\nhigh guess\n";
    cin >> high;
    
    double start;
    cout << "\nstart guess\n";
    cin >> start;
    
    double tolerance;
    
    cout << "\nTolerance\n";
    cin >> tolerance;
    
    BSCall theCall(r,d,Expiry,Spot,Strike); //function object for a vanilla call with all given parameters
    
    double vol =
        Bisection(Price,low,high,tolerance,theCall);
    
    // check the price
    double PriceTwo =
        BlackScholesCall(Spot,Strike,r,d,vol,Expiry);
    
    cout << "\nfor bisection method:\n";
    cout << "\nimplied vol is:  " << vol << " \noption price by implied volatility is: "
    << PriceTwo << "\n";
    
    BSCallTwo theCall2(r,d,Expiry,Spot,Strike);
    
    vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, start,tolerance, theCall2);
    
    PriceTwo =BlackScholesCall(Spot,Strike,r,d,vol,Expiry);
    
    cout << "\nfor Newton method:\n";
    cout << "\nimplied vol is:  " << vol << " \n option price by implied volatility is: "
    << PriceTwo << "\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;
}


