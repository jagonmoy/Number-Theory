 - ## PREREQUISITE : GCD 
   - ### Explanation :
   <br><br>Euclidian Algorithm determines the GCD of two numbers a and b . But Extended Euclidian Algorithm determines ,<br><br>
   the value x and y along with GCD of a,b in ax+by = GCD(a,b) ... eq(1) <br><br>
   we know that , GCD(a,b) = GCD(b,a%b) , here GCD(b,a%b) = b.x1 + (a mod b).y1 ....... eq(2) <br><br>
   now , a mod b = a - floor(a/b).b <br><br>
   so eq(2) can be written as ,<br><br>
   GCD(b,a%b) = b.x1 + (a - floor(a/b).b).y1 <br><br>
   => b.x1 + y1.a - floor(a/b).b.y1 <br><br>
   => a.y1 + b.x1 - b.floor(a/b).y1 <br><br>
   => a.y1 + b.(x1 - floor(a/b).y1) ......... eq(3)<br><br><br>
   we know ,GCD(a,b) = GCD(b,a%b) <br><br>
   so from eq(1) and eq(3) we can say that ,<br><br>
   a.x + b.y = a.y1 + b.(x1 - floor(a/b).y1) <br><br>
   so, x = y1 ........ eq(4) <br><br>
   and y = x1 - floor(a/b).y1 ........... eq(5) <br><br>
   Now , GCD(b,a%b) is the next step of GCD(a,b) so if we know the value of x1,y1 in GCD(b,a%b) then from this we can compute the value of a and b in GCD(a,b)<br><br>
   so we need to know the value of x1,y1 from which we can compute x,y backwardly .<br><br>
   Now see , we can write GCD(a,0) = a.1 + b.0 , so when the value of b is zero the value of x,y is 1 and 0 . based on this value we can compute the earlier x,y values and by 
   computing backwardly we can get the actual values of x and y in GCD(a,b) = ax + by equation . <br><br>
   let see a example , <br><br>
   GCD(80,55) = 80.x + 55.y <br><br> 
   here we need to find the value of x,y and GCD(80,55) <br><br>
   Lets do it recursively . from top to bottom the step will be , <br><br>
   GCD(80,55) <br><br> 
   GCD(55,25) <br><br>
   GCD(25,5) <br><br>
   GCD(5,0) <br><br>
   now let us compute from GCD(5,0) from bottom to top because we know GCD(a,0) = a.1 + b.0 <br><br>
   here x = 1 and y = 0 <br><br>
   now this value of x and y will be regarded as x1 and y1 in GCD(25,5) and according to eq(4) and eq(5) x = y1 and y = x1 - floor(a/b).y <br><br>
   new x = 0 <br><br>
   new y = 1 - 0.(25/5) = 1 <br><br>
   this value of x and y will be regarded as x1 and y1 in GCD(55,25) now,<br><br>
   new x = 1 <br><br>
   new y = 0 - 1.(55/25) = -2 <br><br>
   this value of x and y will be regarded as x1 and y1 in GCD(80,55) now,
   new x = -2 ;
   new y = 1 - (-2).(80/55) = 3 
   this are the actual and final values of x and y so GCD(80,55) = 80.(-2) + 55.(3) <br><br>
   so in code we need to find the value of x ,y and  gcd both.<br><br>
   to compute x,y <br><br>
   we need to  start from GCD(a,0) step to GCD(a,b) .<br><br>  
   But to compute gcd <br><br> 
   we need to start from GCD(a,b) step to GCD(a,0) <br><br>
  ( we saw this in basic Euclidian algorithm ) <br><br> 
  this two methods are completely opposite one is from top to bottom and other is from bottom to top . now how to compute x,y and GCD together ??????<br><br>
  to solve this issue we need to understand pass by reference method . I tried to explain the code below by an example .<br><br>
  - ### Code <br><br><br>
  <img src="Images/Extended_Euclid.png" width="600" > <br><br><br>
  - ### Code Explanation <br><br>
  here we passed the value of a and b , and passed the address of x,y <br><br>
  let us see a example<br><br> 
  suppose x has a memory address of 101 and y has a memory address of 102<br><br>
  here we passed the value of <br><br>
  step 1 : <br><br>
  -------- <br><br>
  80,55,address of x (101) , address of y (102)<br><br>
  then we created x1 and y1 for this step, address of x1 103 , address of y1 104<br><br>
  passed to the function<br><br>
  step 2<br><br>
  -------- <br><br>
  55,25,address of prevous x1 (103) ,address of previous y1 (104)<br><br>
  then we created x1 and y1 for this step , address of x1 105 , address of y1 106<br><br>
  passed to the function <br><br>
  step 3 <br><br>
  -------- <br><br>
  25,5,address of previous x1 (105) , address of previous y1 (106)<br><br>
  then we created x1 and y1 for this step , address of x1 107 , address of y1 108<br><br>
  passed to the function<br><br>
  step 4<br><br>
  ------- <br><br>
  5,0,address of previous x1 (107) , address of previous y1 (108)<br><br>
  now we reached the step of 5,0 this is the base case <br><br>
  in this state the value of * x = 1 and * y = 0 , this values will be assign to address 107 and address of 108 <br><br>
  so  this value of * x and * y will be used as x1 and y1 in step 3 <br><br>
  step 3<br><br>
  ------ <br><br>
  now x1 = 1 (address 107) <br><br>
  now y1 = 0 (address 108) <br><br>
  now * x = 0 (address 105 ) <br><br>
  now * y = 1 (address 106 ) <br><br>
  these will be the values of x1 and y1 in step 2<br><br>
  step 2<br><br>
  ------- <br><br>
  now x1 = 0 (address 105 )<br><br>
  now y1 = 1 ( address 106 ) <br><br>
  now * x = 1 ( address of 103 ) <br><br>
  now * y = 0 - (55/25).1 = -2 (address of 104 )<br><br>
  these will be the value of x1 and y1 in step 1 <br><br>
  step 1<br><br>
  ------ <br><br>
  now x1 = 1 ( address of 103) <br><br>
  now y1 = -2 ( address of 104) <br><br>
  and * x = -2  ( address of 101) <br><br>
  now * y =  1 - (-2).(80/55) = 3 ( address of 102 )<br><br>
  now this was the primary address of x and y so now we got the answer -2 and 3 .<br><br>
  so GCD(80,55) = 80.(-2) + 55.(3)<br><br>
