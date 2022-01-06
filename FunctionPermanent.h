#ifndef UNTITLED2_FUNCTIONPERMANENT_H
#define UNTITLED2_FUNCTIONPERMANENT_H
#include "Function.h"

//permanent Function

class FunctionPermanent: public Function{
    double num;
    // Function = num
public:
    FunctionPermanent(double num);
    double Evaluate(const std::map<std::string,double> &variables)const {return this->num;};
    SharedPtr<Function> DeriveBy(const std::string& variable)const;
    ~FunctionPermanent(){};
};


#endif //UNTITLED2_FUNCTIONPERMANENT_H
