#ifndef UNTITLED2_FUNCTIONSUM_H
#define UNTITLED2_FUNCTIONSUM_H

#include "Function.h"
#include "SharedPtr.h"

//sum Function
namespace OOP_Hw3{
    class FunctionSum : public Function{
    SharedPtr<Function> leftFunction;
    SharedPtr<Function> rigthFunction;
    //function = leftFunction + rigthFunction

    public:
        FunctionSum(SharedPtr<Function> left, SharedPtr<Function> rigth);
        virtual double Evaluate(const std::map<std::string,double> &variables) const;
        virtual SharedPtr<OOP_Hw3::Function> DeriveBy(const std::string& variable) const;
        ~FunctionSum(){};
    };
}
#endif //UNTITLED2_FUNCTIONSUM_H
