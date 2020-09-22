VL findingdivisors(ull n) {
    VL divisors ;
    for ( ll i = 1 ; i*i <= n ; i++) {
        if ( n%i == 0 ) {
            divisors.PB(i);
            if ( i != n/i ) divisors.PB(n/i);
        }
    }
    return divisors ;
}
