- ## PREREQUISITE : Basic Logarithm Knowledge , Digits of Factorial 
- ## EXPLANATION : 
  <br><br> Idea is very simple . In past , for one iteration  we divided log10(i) by log10(b) and added this to our result . But this time we have precalculated only log10(i) by 
  assuming the base 10 . We have also stored the sum in digit[] array for corresponding iteration. 
  Then for every call of calculating_digits_of_n_factorial_in_b_base() function we have divided the precalculated value by log10(b) and returned the floor value .
