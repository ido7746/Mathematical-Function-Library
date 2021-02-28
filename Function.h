#ifndef UNTITLED2_FUNCTION_H
#define UNTITLED2_FUNCTION_H

#include <list>
#include <string>
#include <map>
#include "SharedPtr.h"


namespace OOP_Hw3{
    class Function{
    protected:
        std::list<std::string> variables;//list of the variables in the function
        void MargeVatiable(std::list<std::string> listR, std::list<std::string> listL);//marge lists with out duplicate

    public:
        virtual ~Function(){};
        virtual double Evaluate(const std::map<std::string,double> &variables)const = 0;//return the value
        std::list<std::string> Variables() const{return this->variables;};//return the list of the variables
        virtual SharedPtr<OOP_Hw3::Function> DeriveBy(const std::string& variable)const = 0;//return pointer to the derive function
        std::map<std::string, std::map<std::string, SharedPtr<Function> > > Hessian() const;//return the Hessian of the function
    };

}

#endif //UNTITLED2_FUNCTION_H
