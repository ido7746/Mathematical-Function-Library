#include "FunctionMulti.h"


FunctionMulti::FunctionMulti(SharedPtr <Function> left, SharedPtr <Function> rigth): leftFunction(left),rigthFunction(rigth)
{
    Function::MargeVatiable(rigth->Variables(), left->Variables());//marge the Lists
}


double FunctionMulti::Evaluate(const std::map<std::string, double> &variables) const
{
    double sumRigth=this->rigthFunction->Evaluate(variables);//get the value of the rigth Funcrion
    double sumLeft=this->leftFunction->Evaluate(variables);//get the value of the left Funcrion
    return sumLeft*sumRigth;
}

SharedPtr<Function> FunctionMulti::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> rigthDeriveMulti = this->rigthFunction->DeriveBy(variable);//get the derive of the rigth fuction
    SharedPtr<Function> leftDeriveMulti = this->leftFunction->DeriveBy(variable);//get the derive of the left fuction
    SharedPtr<Function> sumLeftFunction = new FunctionMulti(this->leftFunction,rigthDeriveMulti);//make new function for the rigth side of the derive
    SharedPtr<Function> sumRigthFunction = new FunctionMulti(this->rigthFunction,leftDeriveMulti);//make new function for the left side of the derive

    return new FunctionSum(sumLeftFunction,sumRigthFunction);//return poiter to the drived
}