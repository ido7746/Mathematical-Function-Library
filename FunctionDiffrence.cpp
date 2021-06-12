#include "FunctionDiffrence.h"

OOP_Hw3::FunctionDiffrence::FunctionDiffrence(SharedPtr<Function> left, SharedPtr<Function> rigth):leftFunction(left),rigthFunction(rigth)
{
    Function::MargeVatiable(rigth->Variables(), left->Variables());//marge the lists
}


double OOP_Hw3::FunctionDiffrence::Evaluate(const std::map<std::string, double> &variables) const
{
    double sumRigth=this->rigthFunction->Evaluate(variables);
    double sumLeft=this->leftFunction->Evaluate(variables);
    return sumLeft-sumRigth;
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::FunctionDiffrence::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> rigthDerive = this->rigthFunction->DeriveBy(variable);
    SharedPtr<Function> leftDerive = this->leftFunction->DeriveBy(variable);
    return new FunctionDiffrence(leftDerive,rigthDerive);
}


