#include "FunctionPermanent.h"

OOP_Hw3::FunctionPermanent::FunctionPermanent(double num):num(num)
{
    this->variables.push_front("NoN");
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::FunctionPermanent::DeriveBy(const std::string &variable) const
{
    return new FunctionPermanent(0);
}

