ll  check[1000000];
vector<ll> sieve(ll n) {
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

VL segmented_sieve(ll a, ll b) {
    if ( a == 1) a++ ;
    ll status[b-a+5];
    memset(status,0,sizeof(status));
    VL checkerprimes = sieve(sqrt(b)+1);
    VL neededprimes ;
    for ( ll i = 0 ; i < checkerprimes.size() ; i++) {
        ll p = checkerprimes[i];
        ll j = p*p ; 
        if ( j < a) j = ((a+p-1)/p)*p ;
        for ( ; j <= b ; j += p ) status[j-a] = 1 ;
    }
    for ( ll i = a ; i <= b ; i++) if (!status[i-a]) neededprimes.PB(i);
    return neededprimes ;
}
