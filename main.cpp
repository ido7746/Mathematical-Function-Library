#include "Function.h"
#include <list>
#include "Function.h"
#include "FunctionId.h"
#include "FunctionPermanent.h"
#include "MathematicalOperations.h"
#include "FunctionSum.h"
#include "FunctionMulti.h"
#include "FunctionDivide.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <iomanip> // Set floating point precision
#include "MathematicalOperations.h"

using namespace OOP_Hw3;
using std::string;
using std::map;
typedef map<string, map<string, SharedPtr<Function> > > Hessian;

map<string, double> CreatePoint(double x, double y, double z)
{
    map<string, double> point = map<string, double>();
    point["x"] = x;
    point["y"] = y;
    point["z"] = z;
    return point;
}


void PrintHessianAtPoint(const Hessian& hessian, const map<string, double>& point, const string& funcName)
{
    for (Hessian::const_iterator it1 = hessian.begin(); it1 != hessian.end(); ++it1)
    {
        string var1 = it1->first;
        for (map<string, SharedPtr<Function> >::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            string var2 = it2->first;
            double derivativeValue = it2->second->Evaluate(point);
            std::cout << "dd" << funcName << " / d" << var1 << "d" << var2 << " = ";
            std::cout << derivativeValue << std::endl;
        }
    }
}

int main()
{
/*    // Set floating point printing precision to two decimal points
    std::cout << std::fixed << std::setprecision(2);

    SharedPtr<Function> x = var("x");
    SharedPtr<Function> y = var("y");
    SharedPtr<Function> z = var("z");
    map<string, double> point1 = CreatePoint(1, 0.1, 3);
    map<string, double> point2 = CreatePoint(-2.2, 4, -1.3);


    SharedPtr<Function> f1 = x * x + x - cnst(20);
    SharedPtr<Function> f2 = x * y * z + y * z / x;
    SharedPtr<Function> f3 = cnst(0.5*9) * x * x + cnst(8) * x * y  + cnst(0.5 * 7) * y * y;

    std::cout << "point1 = (1, 0.1, 3)" << std::endl;
    std::cout << "point2 = (-2.2, 4, -1.3)" << std::endl;

    std::cout << "*************" << std::endl;
    std::cout << "f1(point1) = " << f1->Evaluate(point1) << std::endl;
    std::cout << "f1(point2) = " << f1->Evaluate(point2) << std::endl;
    std::cout << "f2(point1) = " << f2->Evaluate(point1) << std::endl;
    std::cout << "f2(point2) = " << f2->Evaluate(point2) << std::endl;

    std::cout << "f1'x(point1)   = " << f1->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2'x(point1)   = " << f2->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2''xy(point1) = " << f2->DeriveBy("x")->DeriveBy("y")->Evaluate(point2) << std::endl;

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f2 at point2" << std::endl;

    PrintHessianAtPoint(f2->Hessian(), point2, "f2");

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f3 at point2" << std::endl;

    PrintHessianAtPoint(f3->Hessian(), point2, "f3");

    return 0;*/

    // Set floating point printing precision to two decimal points
    std::cout << std::fixed << std::setprecision(2);

    SharedPtr<Function> x = var("x");
    SharedPtr<Function> y = var("y");
    SharedPtr<Function> z = var("z");
    map<string, double> point1 = CreatePoint(1, 0.1, 3);
    map<string, double> point2 = CreatePoint(-2.2, 4, -1.3);
    map<string, double> point3 = CreatePoint(0, 0, 0);
    map<string, double> point4 = CreatePoint(1.1, 2.2, 3.3);
    map<string, double> point5 = CreatePoint(1, 1, 1);



    SharedPtr<Function> f1 = x * x + x - cnst(20);
    SharedPtr<Function> f2 = x * y * z + y * z / x;
    SharedPtr<Function> f3 = cnst(0.5 * 9) * x * x + cnst(8) * x * y + cnst(0.5 * 7) * y * y;
    SharedPtr<Function> f4 = x*x + y*y + z*z;
    SharedPtr<Function> f5 = ((x * x * x) - x) + ((z * z * z) - z) + ((y * y * y) - y);
    SharedPtr<Function> f6 = ((x * x) / (y + z)) + ((y * y) / (x + z)) + ((z * z) / (x + y));


    std::cout << "point1 = (1, 0.1, 3)" << std::endl;
    std::cout << "point2 = (-2.2, 4, -1.3)" << std::endl;
    std::cout << "point3 = (0, 0, 0)" << std::endl;
    std::cout << "point4 = (1.1, 2.2, 3.3)" << std::endl;
    std::cout << "point5 = (1, 1, 1)" << std::endl;

    std::cout << "*************" << std::endl;
    std::cout << "Evaluating Points:-" << std::endl;
    std::cout << "f1(point1) = " << f1->Evaluate(point1) << std::endl;
    std::cout << "f1(point2) = " << f1->Evaluate(point2) << std::endl;
    std::cout << "f2(point1) = " << f2->Evaluate(point1) << std::endl;
    std::cout << "f2(point2) = " << f2->Evaluate(point2) << std::endl;
    std::cout << "f3(point1) = " << f3->Evaluate(point1) << std::endl;
    std::cout << "f3(point2) = " << f3->Evaluate(point2) << std::endl;
    std::cout << "f4(point1) = " << f4->Evaluate(point1) << std::endl;
    std::cout << "f4(point2) = " << f4->Evaluate(point2) << std::endl;
    std::cout << "f5(point3) = " << f5->Evaluate(point3) << std::endl;
    std::cout << "f5(point5) = " << f5->Evaluate(point5) << std::endl;
    std::cout << "f5(point4) = " << f5->Evaluate(point4) << std::endl;
    std::cout << "f6(point1) = " << f6->Evaluate(point1) << std::endl;
    std::cout << "f6(point2) = " << f6->Evaluate(point2) << std::endl;

    std::cout << "*************" << std::endl;
    std::cout << "Derivatives:-" << std::endl;

    std::cout << "f1'x(point1)   = " << f1->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2'x(point1)   = " << f2->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2''xy(point1) = " << f2->DeriveBy("x")->DeriveBy("y")->Evaluate(point2) << std::endl;
    std::cout << "f4'x(point5)   = " << f4->DeriveBy("x")->Evaluate(point5) << std::endl;
    std::cout << "f4'y(point5)   = " << f4->DeriveBy("y")->Evaluate(point5) << std::endl;
    std::cout << "f4'z(point5)   = " << f4->DeriveBy("z")->Evaluate(point5) << std::endl;
    std::cout << "f5'x(point5)   = " << f5->DeriveBy("x")->Evaluate(point5) << std::endl;
    std::cout << "f5'y(point5)   = " << f5->DeriveBy("y")->Evaluate(point5) << std::endl;
    std::cout << "f5'z(point5)   = " << f5->DeriveBy("z")->Evaluate(point5) << std::endl;


    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f2 at point2" << std::endl;

    PrintHessianAtPoint(f2->Hessian(), point2, "f2");

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f3 at point2" << std::endl;

    PrintHessianAtPoint(f3->Hessian(), point2, "f3");

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f4 at point2" << std::endl;

    PrintHessianAtPoint(f4->Hessian(), point2, "f4");

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f5 at point5" << std::endl;

    PrintHessianAtPoint(f5->Hessian(), point5, "f5");

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f6 at point5" << std::endl;

    PrintHessianAtPoint(f6->Hessian(), point5, "f6");

    return 0;
}
