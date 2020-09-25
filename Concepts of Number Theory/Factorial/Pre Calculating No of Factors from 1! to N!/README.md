 - ## PREREQUISITE : Sieve , Prime factorisation , Factorial Factorisation
 - ### Explanation :
 <br><br>
Basic Idea was actually taken from the method of Precalculating No of divisors and sum of divisors . for every power of every prime less than N we added 1 to it's multple .
a small example is described below . <br><br>
suppose from 1 to 15 initially the array was

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0        

for 2^1 <br>                                
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 <br><br>       
for 2^2 <br>                               
0 1 0 2 0 1 0 2 0 1 0 2 0 1 0 <br><br>        
for 2^3 <br>                               
0 1 0 2 0 1 0 3 0 1 0 2 0 1 0 <br><br>          
for 3^1 <br>                               
0 1 1 2 0 2 0 3 1 1 0 3 0 1 1 <br><br>          
for 3^2 <br>
0 1 1 2 0 2 0 3 2 1 0 3 0 1 1 <br><br>
for 5^1 <br>
0 1 1 2 1 2 0 3 2 2 0 3 0 1 2 <br><br> 
for 7^1 <br>
0 1 1 2 1 2 1 3 2 2 0 3 0 2 2 <br><br> 
for 11^1 <br> 
0 1 1 2 1 2 1 3 2 2 1 3 0 2 2 <br><br>
for 13^1 <br>
0 1 1 2 1 2 1 3 2 2 1 3 1 2 2 <br><br>

Now cummlative sum of the array
0 1 2 4 5 7 8 11 13 15 16 19 20 22 24

here the total time complexity will be O( No of primes up to N * log2(N) * log10(log10(N)) )
suppose the N is 10^6 then No of primes will be near 78500 . so it will take 78500*log2(10^6)*log10(log10(10^6)) ) = 1.2 * 10^6 
which is a much better solution and not get TLE .
