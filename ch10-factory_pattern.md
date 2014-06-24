ch10 the factory
=====

#10.1 The problem
a conversion routine from strings and strikes to pay-offs.
add new pay-offs without changing any of the existing files.

#10.2 The basic idea
- an identity string
- the class to communicate with the factory, without explicitly calling anything from the main routine- **global variables**
- the initialization involves a call to a **constructor**, and we can make the constructor do whatever we want
- for each pay-off class -> an **auxiliary class** whose constructor registers the pay-off class with our factory -> declare a global variable of the auxiliary class
- a **template solution** for defining these classes: since these auxiliary classes will all be very similar

##the static variable
- a type of variable guaranteed to come into existence at the moment it is first referred to
- a static variable defined in a function **persists** from one call to the next, and only **disappears when the program exits**.

#10.3 The singleton pattern
- all constructors and assignment operators are made private.
- a way of creating a single factory which can be **referenced from anywhere at any time in the program**


#10.4 Coding the factory
- instance method 
- a method for registering pay-off classes
- a method for creating then
-  a container class to store string identifier for the specific pay-off class and the pointer to the function which actually creates the object in question
-  a method which turns a string plus a strike into a PayOff object


##Map
insert
pair
iterator

#10.5 Automatic registration

#10.7 Key points
In this chapter we have developed the **factory pattern** and the **singleton pattern** in order to give a method of adding new pay-off classes to an interface without modifying existing files.

- The singleton pattern allows us to create a unique global object from a class and provide a way of accessing it.
- The factory pattern allows us to add extra inherited classes to be accessed from an interface without changing any existing files.
- The factory pattern can be implemented using the singleton pattern.
- The standard template library **map class** is a convenient way to associate objects with string identifiers.
- Placing objects in **an unnamed namespace** is a way of ensuring that they are not accessed elsewhere.
- We can achieve automatic registration of classes by making their registration a side-effect of the creation of global variables from a helper class.



