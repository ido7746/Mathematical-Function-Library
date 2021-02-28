#include "FunctionSum.h"
#include "FunctionId.h"
#include "Function.h"
#include <typeinfo>

OOP_Hw3::FunctionSum::FunctionSum(SharedPtr<Function> left, SharedPtr<Function> rigth):leftFunction(left),rigthFunction(rigth)
{
    Function::MargeVatiable(rigth->Variables(), left->Variables());//מוסיף את הערכים של המשתנים לרשימה
}


double OOP_Hw3::FunctionSum::Evaluate(const std::map<std::string, double> &variables) const
{
    double sumRigth=this->rigthFunction->Evaluate(variables);
    double sumLeft=this->leftFunction->Evaluate(variables);
    return sumRigth+sumLeft;
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::FunctionSum::DeriveBy(const std::string &variable) const
{
    SharedPtr<Function> rigthDerive = this->rigthFunction->DeriveBy(variable);//גוזר את החלק הימני
    SharedPtr<Function> leftDerive = this->leftFunction->DeriveBy(variable);//גוזר את החלק השמאלי
    return new FunctionSum(leftDerive,rigthDerive);//יוצר פונקציית חיבור חדשה של הנגזרות
}



