ch9 Solvers, templates, and implied volatilities
=====

##Why need implied volatilty and how to
- traditional to quote prices in terms of the Black–Scholes implied volatility
- The Black–Scholes formula is sufficiently complicated that there is **no analytic inverse** and this inversion must be carried out **numerically**
- use bisection and Newton–Raphson here

##Use function object
const operator()(double x) const
f(y)  is equivalent to f.operator()(y)
- object f can be used with function-like syntax
- f is an object it can contain extra information.

##Templatization
The basic idea of templatization is that you can write code that **works for many classes simultaneously** provided they are required to have certain operations defined with the **same syntax**

invoke the function with the template argument BSCall via Bisection<BSCall> then every T will be converted into a BSCall before the function is compiled.

the standard template library always uses the former syntax

##Newton–Raphson and function template arguments

Newton–Raphson involves two functions, the value and the derivative

a way of specifying which class member function to call at compile time using templatization
a pointer to a member function (restricted to methods of a single class)

syntax:
double (T::\*Derivative)(double) const
TheObject.\*Derivative(y)


##The pros and cons of templatization
- in other chapters, we have used **virtual functions** and **polymorphism**

###Pros
- **Speed**: for templates argument types are decided at the **time of compilation**; for virtual functions the type is not determined until **runtime**
	- No time is spent on deciding which code to run when the code is actually running
	- make extra optimizations 
	
###Cons
- **Size**: As the code is compiled for each template argu- ment used separately, we have multiple copies of very similar code
- **slower compiler times**: much more code would have to be compiled
- harder to debug

##When choose templatization?
- the routine should be short, and potentially re-usable in totally unrelated contexts
- languages exhibit a trade-off between abstraction and efficiency

##Key points
- **Templates** are an alternative to inheritance for coding without knowing an object’s precise type.
- Template code can be faster as function calls are determined at compile time.
- Extensive use of template code can lead to very large executables.
- Pointers to member functions can be a useful way of obtaining generic behaviour.
- Implied volatility can only be computed numerically.







