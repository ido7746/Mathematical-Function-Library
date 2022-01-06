#include "FunctionDiffrence.h"

FunctionDiffrence::FunctionDiffrence(SharedPtr<Function> left, SharedPtr<Function> rigth):leftFunction(left),rigthFunction(rigth)
{
    Function::MargeVatiable(rigth->Variables(), left->Variables());//marge the lists
}


double FunctionDiffrence::Evaluate(const std::map<std::string, double> &variables) const
{
    double sumRigth=this->rigthFunction->Evaluate(variables);
    double sumLeft=this->leftFunction->Evaluate(variables);
    return sumLeft-sumRigth;
}

SharedPtr<Function> FunctionDiffrence::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> rigthDerive = this->rigthFunction->DeriveBy(variable);
    SharedPtr<Function> leftDerive = this->leftFunction->DeriveBy(variable);
    return new FunctionDiffrence(leftDerive,rigthDerive);
}


