ch7 An exotics engine and the template pattern
======
##7.1 Introduction:
###Componnets developed:###
- random number generator
- parameter class
- pay-off class
- statistics gathers
- wrapper template

###Object:
to develop a flexible MC pricer for exotic options

###Assumptions
- now working in a deterministic IR world
- assume BS model for stock price evolution
- derivatives are discrete: value depends on spot on discrete set of times (eg. Asian option)
- generally, it may pay cash-flows at some time. (eg. discrte barrier knock-out option)


##7.2 Identifying components
1. generation of stock price path
2. generation of cash-flows given a stock price -> **a path-dependent exotic option class, return the payoff, separated form IR and volatility**
3. discounting and summing of cash-flows for a given path -> **if deterministic IR, include it in main class**
4. averaging prices over all paths -> **statistics gatherer**

###Template design pattern
base class sets up a structure with methods that control everythings, while the actual work is not defined in the base class (use **pure virtual function**).

##7.3 Communication between components

- option take in a vector of spot values for some time point and get cash-flows -> option have to tell the path gemnerator for **which time it need spot values**
	- cash-flow object
		- GetLookAtTimes(): return an array of time
		- PossibleCashFlowTimes(): for pre-compute the discount factor each time 
		- tell how big the vetor is

###whole procedure

1. path generator <-> option : know times for get spot, return the generator spot 
2. engine <-> option: possible cash-flow time, do pre-computation of discount factor
3. engine <-> option: max number of cash flows, prepare the vector with appropriate size
4. engine <-> generator: each path, get a array of spot price
5. engine <-> option: pass in the spot, return the cash-flows
6. discount the cash-flows, sum them, pass to statistics gatherer



##Implementation
###PathDependent.h
CashFlow class, PathDependent class


##7.5 A BS path generation engine

allow variable IR and dividend rate, variable but deterministic volatilty
 in **ExoticBSEngine.h** and **ExoticBSEngine.cpp.**
