#include "FunctionDivide.h"

FunctionDivide::FunctionDivide(SharedPtr<Function> up, SharedPtr<Function> down):downFunction(down), upFunction(up)
{
    Function::MargeVatiable(up->Variables(), down->Variables());
}


SharedPtr<Function> FunctionDivide::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> upDerive = this->upFunction->DeriveBy(variable);
    SharedPtr<Function> downDerive = this->downFunction->DeriveBy(variable);
    SharedPtr<Function> newUpLeftDerive = new FunctionMulti(upDerive,this->downFunction);
    SharedPtr<Function> newUpRigthDerive = new FunctionMulti(downDerive,this->upFunction);
    SharedPtr<Function> newUp = new FunctionDiffrence(newUpLeftDerive,newUpRigthDerive);
    SharedPtr<Function> newDown = new FunctionMulti(this->downFunction,this->downFunction);
    return new FunctionDivide(newUp,newDown);
}

double FunctionDivide::Evaluate(const std::map<std::string, double> &variables) const
{
    double upSum = this->upFunction->Evaluate(variables);
    double downSum = this->downFunction->Evaluate(variables);
    if(downSum==0){
        std::cout<<"Error: out of range!/n";
    }
    return upSum/downSum;
}
