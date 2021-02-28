#include "Function.h"

void OOP_Hw3::Function::MargeVatiable(std::list<std::string> listR, std::list<std::string> listL)//מחבר את רשימות הערכים עם הרשימות המתקבלות, ללא כפילויות
{
    this->variables.merge(listR);
    this->variables.merge(listL);
    this->variables.sort();
    this->variables.unique();//remove duplicate
    if(this->variables.size()>1)//remove NON
        this->variables.remove("NoN");
}

std::map<std::string, std::map<std::string, SharedPtr<OOP_Hw3::Function> > > OOP_Hw3::Function::Hessian() const
{
    std::map<std::string, std::map<std::string, SharedPtr<OOP_Hw3::Function> > > hessianMatrix;
    for(std::_List_const_iterator<std::string > i = this->variables.begin(); i != this->variables.end(); ++i){//רץ על כל רשימת הערכים
        SharedPtr<OOP_Hw3::Function> firsDeriveByi =  this->DeriveBy(*i);//נגזרת ראשונה לפי המשתנה הראשון
        for(std::_List_const_iterator<std::string > j = this->variables.begin(); j != this->variables.end(); ++j){//רץ עוד פעם על רשימת הערכים
            SharedPtr<OOP_Hw3::Function> secDeriveByj = firsDeriveByi->DeriveBy(*j);//גוזר לפי המשתנה השני
            hessianMatrix[*i][*j] = secDeriveByj;
        }
    }
    return hessianMatrix;
}

