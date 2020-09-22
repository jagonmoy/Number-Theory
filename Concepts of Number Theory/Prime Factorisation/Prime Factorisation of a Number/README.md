- ## PREREQUISITE : Sieve

- ### EXPLANATION LINK :
  [An Excellent Article Regarding Prime Factorisation](https://forthright48.com/prime-factorization-of-integer)
  
- ### EXPLANATION :
   First Run a Sieve Algorithm and find all the Prime Numbers Up to Square root of N . Then Start dividng the Given Number N by the Prime factors Untill N become Undivisible .
   Store the Prime Number which divides N and How many times They divide . 
   Overall Complexity will be O(Sqrt(N)) . Because for the Sieve Algorithm the Complexity will be O(Sqrt(N)) and Inside the Factorisation Function Complexity will be 
   O(Sqrt(N)/ln(sqrt(N)) + log2(N)) . But O(Sqrt(N)) > O(Sqrt(N)/ln(sqrt(N)) + log2(N))  That's Why overall complexity will be But O(Sqrt(N)) .
