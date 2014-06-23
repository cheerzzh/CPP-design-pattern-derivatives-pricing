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

###Templatization
The basic idea of templatization is that you can write code that **works for many classes simultaneously** provided they are required to have certain operations defined with the **same syntax**

invoke the function with the template argument BSCall via Bisection<BSCall> then every T will be converted into a BSCall before the function is compiled.

the standard template library always uses the former syntax

