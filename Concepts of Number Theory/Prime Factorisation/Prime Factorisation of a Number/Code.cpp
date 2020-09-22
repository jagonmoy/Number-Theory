VL sieve(ll n) {
    ll  check[n+5];
    VL primes ;
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;  

    for ( ll i = 3 ; i*i <= n ; i += 2) {                
        if (!check[i]) {                                
            for ( ll j = i*i ; j <= n ; j += 2*i){       
                   check[j] = 1 ;                        
            }                                            
        }                                                
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   
    return primes ;
}

VL primefactorize(ll n) {
    ll primerange = (ll)sqrt(n)+1 ;
    VL primes = sieve(primerange);
    VL primefactors ;
    if ( n == 1) {
        primefactors.PB(1);
        return primefactors;
    }
    for ( ll i = 0 ; primes[i] <= sqrt(n) && i < primes.size() ; i++) {
        while (!(n%primes[i])) {
            n = n/primes[i];
            primefactors.PB(primes[i]);
        }
    }

    if ( n > 1) primefactors.PB(n);
    return primefactors ;
}
