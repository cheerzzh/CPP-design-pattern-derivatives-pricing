//
//  Arrays.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Arrays.h"
#include <algorithm>
#include <numeric>

MJArray::MJArray(unsigned long size)
: Size(size), Capacity(size)
{
	if (Size >0)
	{
		ValuesPtr = new double[size];
		EndPtr = ValuesPtr;
		EndPtr += size;
	}
	else
	{
		ValuesPtr=0;
		EndPtr=0;
	}
    
}


MJArray::MJArray(const MJArray& original)
:
Size(original.Size), Capacity(original.Size)
{
	if (Size > 0)
	{
		ValuesPtr = new double[Size];
		
		EndPtr = ValuesPtr;
        
		EndPtr += Size;
        
		std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
        
	}
	else
	{
        
		ValuesPtr = EndPtr =0;
	}
    
}


MJArray::~MJArray()
{
	if (ValuesPtr >0)
		delete [] ValuesPtr;
}


MJArray& MJArray::operator=(const MJArray& original)
{
	if (&original == this)
		return *this;
    
    
	if (original.Size > Capacity)
	{
		if (Capacity > 0)
			delete [] ValuesPtr;
        
		ValuesPtr = new double[original.Size];
        
		Capacity = original.Size;
        
	}
    
	Size=original.Size;
    
	EndPtr = ValuesPtr;
	EndPtr += Size;
	
	std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
    
    
	return *this;
}

void MJArray::resize(unsigned long newSize)
{
	if (newSize > Capacity)
	{
		if (Capacity > 0)
			delete [] ValuesPtr;
        
		ValuesPtr = new double[newSize];
        
		Capacity = newSize;
        
	}
    
    
	Size = newSize;
    
    EndPtr = ValuesPtr + Size;
    
}



MJArray& MJArray::operator+=(const MJArray& operand)
{
    
	
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply += two arrays must be of same size");
	}
#endif
    
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]+=operand[i];
    
	return *this;
}


MJArray& MJArray::operator-=(const MJArray& operand)
{
    
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply -= two arrays must be of same size");
	}
#endif
    
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]-=operand[i];
    
	
	return *this;
}


MJArray& MJArray::operator/=(const MJArray& operand)
{
	
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply /= two arrays must be of same size");
	}
#endif
    
    
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]/=operand[i];
    
	return *this;
}


MJArray& MJArray::operator*=(const MJArray& operand)
{
	
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply *= two arrays must be of same size");
	}
#endif
    
    
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]*=operand[i];
    
	return *this;
}


/////////////////////////////

MJArray& MJArray::operator+=(const double& operand)
{
    
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]+=operand;
    
	return *this;
}


MJArray& MJArray::operator-=(const double& operand)
{
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]-=operand;
    
	
	return *this;
}


MJArray& MJArray::operator/=(const double& operand)
{
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]/=operand;
    
	return *this;
}


MJArray& MJArray::operator*=(const double& operand)
{
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]*=operand;
    
	return *this;
}


MJArray& MJArray::operator=(const double& val)
{
	for (unsigned long i =0; i < Size; i++)
		ValuesPtr[i]=val;
    
	return *this;
}

double MJArray::sum() const
{
	return std::accumulate(ValuesPtr,EndPtr,0.0);
    
}


double MJArray::min() const
{
	
#ifdef RANGE_CHECKING
	if ( Size==0)
	{
		throw("cannot take min of empty array");
	}
#endif RANGE_CHECKING
    
	double* tmp = ValuesPtr;
	double* endTmp = EndPtr;
    
	return *std::min_element(tmp,endTmp);
    
}


double MJArray::max() const
{
	
#ifdef RANGE_CHECKING
	if ( Size==0)
	{
		throw("cannot take max of empty array");
	}
#endif RANGE_CHECKING
	double* tmp = ValuesPtr;
	double* endTmp = EndPtr;
    
	return *std::max_element(tmp,endTmp);
}

MJArray MJArray::apply(double f(double)) const
{
	MJArray result(size());
    
	std::transform(ValuesPtr,EndPtr,result.ValuesPtr,f);
    
	return result;
    
}