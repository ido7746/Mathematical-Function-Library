#pragma once

#include "FunctionId.h"
#include "FunctionPermanent.h"
#include "FunctionSum.h"
#include "FunctionDiffrence.h"
#include "FunctionMulti.h"
#include "FunctionDivide.h"


namespace OOP_Hw3
{
	SharedPtr<Function> operator+(SharedPtr<Function> f1, SharedPtr<Function> f2)
    {
	    SharedPtr<Function> prtFunction = new FunctionSum(f1,f2);
	    return prtFunction;
    }
	SharedPtr<Function> operator-(SharedPtr<Function> f1, SharedPtr<Function> f2)
    {
	    SharedPtr<Function> ptrFunction = new FunctionDiffrence(f1,f2);
	    return ptrFunction;
    }

	SharedPtr<Function> operator*(SharedPtr<Function> f1, SharedPtr<Function> f2)
    {
	    SharedPtr<Function> ptrFunction = new FunctionMulti(f1,f2);
	    return ptrFunction;
    }

	SharedPtr<Function> operator/(SharedPtr<Function> f1, SharedPtr<Function> f2)
	{
	    SharedPtr<Function> ptrFunction = new FunctionDivide(f1,f2);
	    return ptrFunction;
	}

	SharedPtr<Function> var(const std::string& variableName){
	    SharedPtr<Function> ptr = new FunctionId(variableName);
	    return ptr;
	}

	SharedPtr<Function> cnst(double num){
        SharedPtr<Function> ptr = new FunctionPermanent(num);
        return ptr;
	}

}
