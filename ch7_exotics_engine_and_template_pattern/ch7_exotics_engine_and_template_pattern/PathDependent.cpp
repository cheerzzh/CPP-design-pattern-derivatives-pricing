//
//  PathDependent.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PathDependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_): LookAtTimes(LookAtTimes_)
{
    
}

const MJArray& PathDependent::GetLookAtTimes() const
{
    return  LookAtTimes;
}

