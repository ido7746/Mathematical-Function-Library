#ifndef UNTITLED2_FUNCTIONDIVIDE_H
#define UNTITLED2_FUNCTIONDIVIDE_H

#include "Function.h"
#include "FunctionMulti.h"
#include "FunctionDiffrence.h"
// divide Function

class FunctionDivide : public Function{
    SharedPtr<Function> upFunction;//counter
    SharedPtr<Function> downFunction;
    //function = upFunction/downFunction

public:
    FunctionDivide(SharedPtr<Function> up, SharedPtr<Function> down);//construction
    virtual double Evaluate(const std::map<std::string,double> &variables) const;//return the value
    virtual SharedPtr<Function> DeriveBy(const std::string& variable) const;
    ~FunctionDivide(){};
};


#endif //UNTITLED2_FUNCTIONDIVIDE_H
