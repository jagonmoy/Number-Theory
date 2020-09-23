- ## PREREQUISITE : Sieve , Number of divisors.

- ### EXPLANATION 
  
  The idea is very similar to general Sieve Algorithm . 
  initially Number of divisors for all the Number is 0 .
  Suppose a number X in [1,n] then for this value X we will add 1 to to all of it's multiple . Because , all of it's multiples are divided by X . So , in our Outer loop we will
  increment the value of **i** by 1 and in our inner loop value of **j** will be incremented by **i** each time because we are adding 1 to **i**'s Multiples .
