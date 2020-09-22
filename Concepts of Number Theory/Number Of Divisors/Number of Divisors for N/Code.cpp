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

ll numberofdivisors(ll n) {
    ll primerange = (ll)sqrt(n)+1 ;
    VL primes = sieve(primerange);
    if ( n == 1) return 1 ;
    ll noofdivisors = 1 ;
    for ( ll i = 0 ;  primes[i] <= sqrt(n) && i < primes.size() ; i++) {
        ll cnt = 0 ;
        while (!(n%primes[i])) {
            n = n/primes[i];
            cnt++ ;
        }
        noofdivisors = noofdivisors*(cnt+1);
    }
    if ( n > 1) noofdivisors = noofdivisors*2;
    return noofdivisors ;
}
