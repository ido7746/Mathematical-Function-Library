# Mathematical Function Library
A mathematical multi variable function library writen in cpp.
With this library you can create Function object with standart mathematical syntax, you can also use mathematical operators like +, -, * and /.
Function object also support advanse mathematical methods:

* Hessian - Calculates Hessian for a Function object.
* DeriveBy - Calculates the Function derivitive.
* Evaluate - Calculate the Function value given mapping from each variable to a spesific value.

 
## Example
### Evaluete:
```
SharedPtr<Function> f1 = new FunctionId("x"); // make id Function 
SharedPtr<Function> derivef1 = f1->DeriveBy("x"); //Derive f1 By "x";
map<string, double> point;
point["x"] = 5;
f1->Evaluate(point); // f1(5)

```
