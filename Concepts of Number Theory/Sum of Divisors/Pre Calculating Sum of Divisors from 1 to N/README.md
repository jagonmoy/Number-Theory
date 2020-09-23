 - ## PREREQUISITE : Sieve , Sum of Divisors .
 
 - ### EXPLANATION :
  
  Exactly like the process of Pre calculating Number of Divisors from 1 to N .
  The idea is very similar to general Sieve Algorithm . Initially sum of divisors for all the Number is 0 . Suppose a number X in [1,n] then for this value X we will add X to to 
  all of it's multiple . Because , all of it's multiples are divided by X . So , in our Outer loop we will increment the value of i by 1 and in our inner loop value of j will be
  incremented by i each time because we are adding i to i's Multiples .
