- ## PREREQUISITE : Sieve , Prime factorisation , Number of divisor 
- ### EXPLANATION :
  <br><br>
  Let us Pick 150 , 400 , 25 , 24 these 4 Numbers in 10-base Number system and Prime factorise these Numbers , <br><br>
  150 = 2 x 3 x 5^2 <br>
  400 = 2^4 x 5^2 <br>
  25 = 5^2 <br>
  24 = 2^3 x 3 <br><br>
  Now, you can see from the above numbers, actually, min( power of 5, power of 2) is the number of trailing zeroes in a number. Basically, the Total Number of 10 presented in factorization
  of a number **N** is the total number of trailing zeroes in the 10-base number system. It is true for every Number system. So, If there is at least one occurrence of **b** in a 
  factorization of number from **b-base** number system then the number will have at least one trailing zero in **b-base** number system. Now The question was How many Number
  systems will have trailing zeroes for the number N? so the answer will be the total Numbers of Combinations we can generate from the Prime factors of the number N. <br><br>
  
  suppose ,  504  = 2^3 x 3^2 x 7  <br><br>
  Now in How many Number System 360 can have Trailing zeroes ?? it can have trailing zeroes in <br><br>
  
  2^0 x 3^0 x 7^1  - base Number system <br>
  2^0 x 3^1 x 7^0  - base Number system <br>
  2^0 x 3^1 x 7^1  - base Number system <br>
  2^0 x 3^2 x 7^0  - base Number system <br>
  2^0 x 3^2 x 7^1  - base Number system <br>
  2^1 x 3^0 x 7^0  - base Number system <br>
  2^1 x 3^0 x 7^1  - base Number system <br>
  2^1 x 3^1 x 7^0  - base Number system <br>
  2^1 x 3^1 x 7^1  - base Number system <br>
  2^1 x 3^2 x 7^0  - base Number system <br>
  2^1 x 3^2 x 7^1  - base Number system <br>
  2^2 x 3^0 x 7^0  - base Number system <br>
  2^2 x 3^0 x 7^1  - base Number system <br>
  2^2 x 3^1 x 7^0  - base Number system <br>
  2^2 x 3^1 x 7^1  - base Number system <br>
  2^2 x 3^2 x 7^0  - base Number system <br>
  2^2 x 3^2 x 7^1  - base Number system <br> 
  2^3 x 3^0 x 7^0  - base Number system <br>
  2^3 x 3^0 x 7^1  - base Number system <br>
  2^3 x 3^1 x 7^0  - base Number system <br>
  2^3 x 3^1 x 7^1  - base Number system <br>
  2^3 x 3^2 x 7^0  - base Number system <br>
  2^3 x 3^2 x 7^1  - base Number system <br><br>
  
  Basically All of them r Divisors of 504 . 1 is also a divisor of 504 but we are not considering any 1-base Number system . so What we can do is , We will just calculate 
  the number of divisors for the given Number N and then subtract 1 from it and that is our answer!!
  
