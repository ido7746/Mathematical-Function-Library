#ifndef UNTITLED2_FUNCTIONDIFFRENCE_H
#define UNTITLED2_FUNCTIONDIFFRENCE_H

#include "Function.h"

//difference Function

class FunctionDiffrence : public Function{
    SharedPtr<Function> leftFunction;
    SharedPtr<Function> rigthFunction;
    //function = leftFunction - rigthFunction

public:
    FunctionDiffrence(SharedPtr<Function> left, SharedPtr<Function> rigth);//construction
    virtual double Evaluate(const std::map<std::string,double> &variables) const;//return the value
    virtual SharedPtr<Function> DeriveBy(const std::string& variable) const;//return pointer to the derive function
    ~FunctionDiffrence(){};
};


#endif //UNTITLED2_FUNCTIONDIFFRENCE_H
