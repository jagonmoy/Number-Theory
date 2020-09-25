- ## PREREQUISITE  : Sieve , Euler Phi .

  - ### EXPLANATION :
       Let Us Assume Two Numbers **a** and **m** and their **GCD(a,m) = g**  <br><br>
       Formally , **GCD(a,m) = g ...eq(1)** <br><br>
       **where , 0 <= a <= m ... eq(2) , a = ga' and m = gm'** <br><br>
       now putting the value of **a** and **m** into eq(1) , <br><br>
       **GCD(ga',gm') = g** <br><br>
       **=> g x GCD(a',m') = g**<br><br>
       **=> GCD(a',m') = 1 ...eq(3)** <br><br>
       **That Means, Instead of Finding GCD(a,m) = g we can find GCD(a',m') = 1** <br><br>
       **Now again if we divide the Equation 2 by g** <br><br>
       **0 <= a' <= m' ...eq(4)** <br><br>
       **Now as we can see , a' is always less or equal than m' and instead of finding GCD(a,m) = g we can find GCD(a',m') = 1 <br><br>
       That means, Pointing to our main Question , Instead of Finding How many Number from 1 to N has GCD(i,N) = g we need to find ,<br><br>
       How many Numbers From 1 to N' (N' = N/g) has GCD(i,N') = 1 . In other words we need find phi(N') . So, We need to Find phi(N/g)**
       
