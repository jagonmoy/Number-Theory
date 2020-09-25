double digits[1000005];
double  precalculating_digits_of_n_factorial(ll n) {
    double x = 0;
    for ( ll i = 1; i <= n; i++ ) {
        x += log10 (i) ;
        digits[i] = x ;
    } 
    return x;
}
ll calculating_digits_of_n_factorial_in_b_base(ll n, ll b) {
    ll x = digits[n]/log10(b)+1+eps ;
    return x ;
}
