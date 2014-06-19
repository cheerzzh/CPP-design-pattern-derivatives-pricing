ch6: A random number class

a class to encapsulate random number generation
default: rand

**Why need random number class?**

1. consideration:
- consistency across compilers
- not know compiler implementation

2. Monte Carlo simulation must be reproducible
- use srand to set seed for rand
- but seed is global variable: casue unrelated pieces of code affect each other

3. We can decorate the random number class
- if use antithetic sampling: use decorator class to implement, no changes to simulator class

4. not use pseudo-random, but low-discrepancy(quasi-random)
- space-filling property -> make simulation converge faster

**Design Consideration**

1. use abstract base class: to have many random number generators
2. method to set simulation dimensionality: number of random draws needed to simulate one path
3. creation of uniform and conversion them into other distribution
4. method to reset the generator to initial state and set seed
5. method to skip path: ensure different stream of random number
6. copy a unknow-type random generator
7. let U(0,1) not take on 0 or 1

**linear congruential generator and adapter pattern**

- by Park& Miller, minimal standard generator
- two pieces: 
	- a small inner class that develop a random generator, return one integer when calles
	- larger class: turn output into a vector of uniforms
- adapter pattern: write a class(an intermediary class) around it which adapts its interface into what we want
- algorithm based on modular arithmetic

**Antithetic sampling via decoration**

- goal: implement it in a way that it can be used with any random generator
