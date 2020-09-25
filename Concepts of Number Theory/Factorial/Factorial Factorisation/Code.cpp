ll  check[1000005];
VL primes ;
void sieve(ll n) {
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;    //the numbers which are not prime that means even numbers are marked by 1

    for ( ll i = 3 ; i*i <= n ; i += 2) {                // Even numbers are not prime so we will check only odd numbers and increment the number by 2 to avoid even number.
        if (!check[i]) {                                 // if  check[i] = 0 that means if the i value is a prime we will procced
            for ( ll j = i*i ; j <= n ; j += 2*i){       // here we are starting not by j = i+i we are starting by j = i*i because the numbers less than i*i are already 
                   check[j] = 1 ;                        // checked by the numbers less than j so no need to calculate them further . and each time we will increment the
            }                                            // numbers by 2*i because if this is a odd number then just incrementing i it will be even and even numbers 
        }                                                // numbers are not prime so no need to check this .
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   // only taking the primes numbers in vector
    return ;
}
MLL factorialfactorization(ll n) {
    sieve(1000000);
    MLL factors ;
    for ( ll i = 0 ; primes[i] <= n && i < primes.size() ; i++) {
        ll freq = 0 ;
        ll x = n ;
        while(x) {
            freq += x/primes[i];
            x = x/primes[i];
        }
        if ( freq != 0) factors[primes[i]] = freq ; 
    }
    return factors ;
}
