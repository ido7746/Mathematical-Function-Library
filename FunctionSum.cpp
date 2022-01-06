#include "FunctionSum.h"
#include "FunctionId.h"
#include "Function.h"
#include <typeinfo>

FunctionSum::FunctionSum(SharedPtr<Function> left, SharedPtr<Function> rigth):leftFunction(left),rigthFunction(rigth) {
    Function::MargeVatiable(rigth->Variables(), left->Variables());

}
double FunctionSum::Evaluate(const std::map<std::string, double> &variables) const
{
    double sumRigth=this->rigthFunction->Evaluate(variables);
    double sumLeft=this->leftFunction->Evaluate(variables);
    return sumRigth+sumLeft;
}

SharedPtr<Function> FunctionSum::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> rigthDerive = this->rigthFunction->DeriveBy(variable);
    SharedPtr<Function> leftDerive = this->leftFunction->DeriveBy(variable);
    return new FunctionSum(leftDerive,rigthDerive);
}



