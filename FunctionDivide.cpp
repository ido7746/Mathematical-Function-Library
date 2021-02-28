#include "FunctionDivide.h"

OOP_Hw3::FunctionDivide::FunctionDivide(SharedPtr<Function> up, SharedPtr<Function> down):downFunction(down), upFunction(up)
{
    Function::MargeVatiable(up->Variables(), down->Variables());
}


SharedPtr<OOP_Hw3::Function> OOP_Hw3::FunctionDivide::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> upDerive = this->upFunction->DeriveBy(variable);//נגזרת של המונה
    SharedPtr<Function> downDerive = this->downFunction->DeriveBy(variable);//נגזרת של המחנה
    SharedPtr<Function> newUpLeftDerive = new FunctionMulti(upDerive,this->downFunction);//הנגזרת של החלק השמאלי של המונה
    SharedPtr<Function> newUpRigthDerive = new FunctionMulti(downDerive,this->upFunction);//הנגזרת של החלק הימני של המונה
    SharedPtr<Function> newUp = new FunctionDiffrence(newUpLeftDerive,newUpRigthDerive);//פונקציית הפרש חדשה למונה שהיא הנגגזרת שלו
    SharedPtr<Function> newDown = new FunctionMulti(this->downFunction,this->downFunction);//המחנה בריבוע
    return new FunctionDivide(newUp,newDown);
}

double OOP_Hw3::FunctionDivide::Evaluate(const std::map<std::string, double> &variables) const
{
    double upSum = this->upFunction->Evaluate(variables);
    double downSum = this->downFunction->Evaluate(variables);
    if(downSum==0){
        std::cout<<"Error: out of range!/n";
    }
    return upSum/downSum;
}