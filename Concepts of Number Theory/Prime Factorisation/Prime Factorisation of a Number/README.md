- ## PREREQUISITE : Sieve

- ### EXPLANATION LINK :
  [An Excellent Article Regarding Prime Factorisation](https://forthright48.com/prime-factorization-of-integer)
  
- ### EXPLANATION :
   First Run a Sieve Algorithm and find all the Prime Numbers Up to Square root of N . 
   Then Start dividng the Given Number N by the Prime factors less than sqrt(N) Untill N become Undivisible . This will take sqrt(N)/ln(sqrt(N)) time .Store the Prime Number which    divides N and How many times They divide . This will take log2(N) time . So overall , Inside the Factorisation Function Complexity will be O(Sqrt(N)/ln(sqrt(N))xlog2(N)) 
   
   
   But Overall Complexity will be O(Nln(N)) . Because for the Sieve Algorithm the Complexity will be O(Nln(N)) and Inside the Factorisation Function Complexity will be 
   O(Sqrt(N)/ln(sqrt(N))xlog2(N)) . But O(NlnN) > O(Sqrt(N)/ln(sqrt(N))xlog2(N))  That's Why overall complexity will be But O(Nln(N)) . But if there is Multiple Test cases
   and O(Tx(Sqrt(N)/ln(sqrt(N))xlog2(N)) > O(Nln(N)) then the complexity will be O(Tx(Sqrt(N)/ln(sqrt(N)) + log2(N))
