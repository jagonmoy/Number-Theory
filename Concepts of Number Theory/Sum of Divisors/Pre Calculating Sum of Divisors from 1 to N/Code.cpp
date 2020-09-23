ll sum_of_divisors[100005];
void precalculating_sum_of_divisors_1_to_n(ll n) {
   for ( ll i = 1 ; i <= n ; i++) {
       for ( ll j = i ; j <= n ; j += i) {
           sum_of_divisors[j]+= i ;   // everytime a number that is divided by i we are adding i to divisor[j]
       }
   } 
}
