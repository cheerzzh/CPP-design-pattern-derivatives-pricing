//
//  ExoticBSEngine.h
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch7_exotics_engine_and_template_pattern__ExoticBSEngine__
#define __ch7_exotics_engine_and_template_pattern__ExoticBSEngine__

#include "ExoticEngine.h"
#include "Random2.h"


// path is a array of spot values at times specified by the product
class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                    const Parameters& R_,
                    const Parameters& D_,
                    const Parameters& Vol_,
                    const Wrapper<RandomBase>& TheGenerator_,
                    double Spot_);
    
    virtual void GetOnePath(MJArray& SpotValues);
    virtual ~ExoticBSEngine(){}
    
private:
    Wrapper<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
    
};

#endif /* defined(__ch7_exotics_engine_and_template_pattern__ExoticBSEngine__) */
