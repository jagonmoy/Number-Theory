ll divisors[100005];
void precalculating_number_of_divisors_1_to_n(ll n) {
   for ( ll i = 1 ; i <= n ; i++) {
       for ( ll j = i ; j <= n ; j += i) {
           divisors[j]++ ;       // everytime a number that is divided by i we are adding 1 to divisor[j]
       }
   } 
}
