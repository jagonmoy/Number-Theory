- ## PREREQUISITE : Sieve , Prime factorisation , Factorial Factorisation 

- ### Explanation : 
<br><br> Suppose we need to find what will be result if we divide N! by a number M . <br>
- First we need to primefactorize the number M .
- Then we will prime factorise the number N! .
- Now we will check every prime factors that is presented in M whether it's power in M is less than it's power in N! . if it is not then we will break and print -1 .
Because it is impossible to divide . On the Contrary , If the power of prime factor in M is less than it's power in N! then  we will Subtract the power of prime in M from Power of Prime in N! .
- Now we need to print the Remaining Power for every prime factor in N! <br><br>

Overall complexity for diving a Number N! by M will be O( No of primes in max(sqrt(M),N) * log2(max(sqrt(M),N)))
if there is multple test case we will precalculate sieve .
So if there is T test cases the complexity will be O(T*No of primes in max(sqrt(M),N) * log2(max(sqrt(M),N))
