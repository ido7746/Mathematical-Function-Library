#ifndef UNTITLED2_FUNCTIONVARIABEL_H
#define UNTITLED2_FUNCTIONVARIABEL_H

#include "Function.h"
#include "FunctionPermanent.h"
#include "SharedPtr.h"
// ID Function

class FunctionId : public Function{
/*   Function(x)=x*/
public:
    FunctionId(const std::string &varible);
    double Evaluate(const std::map<std::string,double> &variables)const ;
    SharedPtr<Function> DeriveBy(const std::string& variable) const;
    ~FunctionId(){};
};


#endif //UNTITLED2_FUNCTIONVARIABEL_H
