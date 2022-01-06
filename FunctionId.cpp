#include "FunctionId.h"
#include "map"
#include <string>


SharedPtr<Function> FunctionId::DeriveBy(const std::string &variable) const
{
    if(this->variables.empty()==false&&variable==this->variables.front())//check if we derive by the variable of the function
        return new FunctionPermanent(1);//make pernament Function of 1
    else
        return new FunctionPermanent(0);//make pernament function of 0
}


double FunctionId::Evaluate(const std::map<std::string,double> &variables) const
{
    std::string temp=this->variables.front();
    double num=variables.at(temp);
    return num;
}

FunctionId::FunctionId(const std::string &varible) {
    this->variables.push_front(varible);
}


