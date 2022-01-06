#include "FunctionPermanent.h"

FunctionPermanent::FunctionPermanent(double num):num(num)
{
    this->variables.push_front("NoN");
}

SharedPtr<Function> FunctionPermanent::DeriveBy(const std::string &variable) const
{
    return new FunctionPermanent(0);
}

