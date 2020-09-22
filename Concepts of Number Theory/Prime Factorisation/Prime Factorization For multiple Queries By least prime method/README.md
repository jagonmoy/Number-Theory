- ## PREREQUISITE : Sieve , Normal Prime Factorisation

- ### Why Should we learn this method of Prime factorisation ??? 

   Suppose there is 10^7 test cases and every Number N can be up to 10^6 . The Time limit is 2 seconds . Now what will be the Complexity if we use our General Prime factorisation 
   Method and Can we execute our solution within time limit ?? or it will get TLE ??
   
   Now ,In general Prime Factorisation Method,  First we will have to run a Sieve up to sqrt(N) . Because to find Prime factors of N we only need to take the factors <= sqrt(N) .
   Because If a Number is divisble then Obviously it will have divisor less than it's Square root value . We can precalculate and store the Prime Numbers by using Sieve Method 
   before running the test cases Because we know the maximum value of N. Limit of N is atmost 10^6 so for sieve we need to pass Sqrt(10^6) in Sieve Method and that is Sieve(10^3)
   . Complexity of Sieve for  any n is O(nxln(n)) . In Sieve ,
   
   n = sqrt(N) so O(nxln(n)) is actually O ( sqrt(N)xln(sqrt(N)) ) 
   
   now sqrt(N) = 10^3 so,
   this Sieve will take 10^3 x ln(10^3) = 7x10^3 operations
   
   Now for Every Test Case , we will run Prime factorisation Function and The Complexity of Prime factorisation function is 
   
   => O(sqrt(N)/ln(sqrt(N)) + log2(N)) 
   
   => O(sqrt(N)/ln(sqrt(N)))  
   
   ( Because , sqrt(N)/ln(sqrt(N) > log2(N) )
   
   So , if N is Atmost 10^6 then It will take sqrt(10^6)/ln(sqrt(10^6)) = 10^3/ln(10^3) = 1.4x10^2 operations and Number of Test case is 10^7 .
   
   so Total Complexity for This Algothim will be
   
   O(sqrt(N)xln(sqrt(N)) + Tx(sqrt(N)/ln(sqrt(N)) + log2(N))) 
   
   => (7x10^3) + (10^7)x(1.4x10^2) 
   
   => (7x10^3) + 1.4x10^9
   
   => 1.4x10^9 , It might get TLE for above time limit .
   
   That's Why We need a Better Solution .
   
- ### Least Prime Method For Prime Factorisation :

    This Method Works Exactly Like Sieve . This is why Complexity is also Same like Sieve . In place of Sieve we will pre calculate Least Prime for Every Prime Number up to N .
    
 - #### What is Exactly Least Prime and how it works in Prime factorisation ??
    
    For a number Y Least Prime is the minimum Possible Prime which divides the number Y . Prime factorisation also works in same Process . We factorise a Number into as minimum 
    possible prime number as we can .So Least Prime Method will help us . 
    
 - #### Now How to Calculate Least Prime ?? 
   
   For every Even Number Least Prime is 2 . So first We will run a loop in O(N) to make 2 as least prime for every Even Number .
   
   Now For every Odd Number starting From 3 , If the Number is Not marked Yet , Then it's Least Prime will be the odd number itself and All of it's Multiple will have the odd 
   number as their Least Prime . Suppose , The Number is 3 then , then 3 will be a least prime for 3 and all of it's multiple 3,6,9,12,15,18,21... will have 3 as their least
   prime .
   
   Now , Why should Not we go forward with a already marked odd number  . Suppose , 9 is a odd Number and Now Multples of 9 are 9,18,27,36,45 .. Now See 
   they are also Multiples of 3 . That's why if we find any Number which is already marked by any other Number then we will not go forward to mark it's multiples .
   
   Now, During the time of marking Mutiples of any odd number we will increment by 2xodd number in place of incrementing by 1xodd Number . Because Odd Number + odd number is 
   Even and for a Even Number it's least prime is 2 . But odd number + odd Number + odd Number will give us another Odd number . 
   
   So Basically The method is very Similar To sieve . Those who understand Sieve this method is a cakewalk for them .
   
 - #### Why should we use this Method and For the Above situation what will be Complexity ?
   
   Least Prime method will take O(Nxln(N)) time .
   After Calculating Least Prime Method the Prime Factorisation Method become very easier .We don't need to Run a Extra loop of sqrt(N) what we used in Previous Method of
   Prime Factorisation . Every time we will divide a Number by it's Least prime and store the Least prime in a vector . And we will continue to divide the Number until it
   becomes 1 . Now the Vector is the Prime factorisation of our number . So Complexity for a number N in this Method will be log2(N) only !!!!! 
   
   But in previous Method The complexity inside Factorisation function was (sqrt(N)/ln(sqrt(N)) + log2(N) . The Difference is huge !! 
   So overall Complexity for this algorithm will be 
   
   O(Tx(log2(N)) + NlnN) 
   
   for T = 10^7 and N = 10^6 ,
   
   => 10^7x(log2(10^6)) + 10^6(ln(10^6))
   
   => 2x10^8 + 1.3x10^7
   
   => 2x10^8 , It takes Less operations than previous previous method and it might Not get TLE in above scenerio .
    
    
    
