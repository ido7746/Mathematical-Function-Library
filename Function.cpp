#include "Function.h"

void Function::MargeVatiable(std::list<std::string> listR, std::list<std::string> listL)
{
    this->variables.merge(listR);
    this->variables.merge(listL);
    this->variables.sort();
    this->variables.unique();//remove duplicate
    if(this->variables.size()>1)//remove NON
        this->variables.remove("NoN");
}

std::map<std::string, std::map<std::string, SharedPtr<Function> > > Function::Hessian() const
{
    std::map<std::string, std::map<std::string, SharedPtr<Function> > > hessianMatrix;
    for(std::list<std::string>::const_iterator i = this->variables.begin(); i != this->variables.end(); ++i){
        SharedPtr<Function> firsDeriveByi =  this->DeriveBy(*i);
        for(std::list<std::string>::const_iterator j = this->variables.begin(); j != this->variables.end(); ++j){
            SharedPtr<Function> secDeriveByj = firsDeriveByi->DeriveBy(*j);
            hessianMatrix[*i][*j] = secDeriveByj;
        }
    }
    return hessianMatrix;
}

