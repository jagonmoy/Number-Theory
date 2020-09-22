- ## PREREQUISITE : IDEA ABOUT PRIME NUMBERS .
 [Brief Introduction to Sieve] (http://www.progkriya.org/gyan/basic-number-theory.html)
 
- ### CODE EXPLANATION :
   The numbers which are not prime are marked by 1 . That's Why Primarily We will mark every Even Numbers by **1** Because Even Numbers are divisble by 2 . 2 is the Only 
   even Number which is a Prime .
   Even numbers are not prime (Except 2 ) so we will check only odd numbers whose **check[i]** value is **0** and increment the value of **i** by 2 in our outer loop to avoid
   even number. This is why if **check[i] = 0** then we will procced to the inner loop .  **Here we are not starting by j = i+i ,But we are starting by j = i*i because the numbers 
   less than i*i are already checked by the numbers < i and 2*i is less than i*i **. So no Don't need to calculate  them further . Each time we will increment the numbers by 2*i
   because if this is a odd number then just incrementing **i** will give us even Numbers and even numbers are not prime so don't need to check this .
   Finally We will store the Numbers as prime if it's Check value is **0** .
