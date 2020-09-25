ll  check[10005];
VL primes ;
MLL factorsM,factorsN ;

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
MLL primefactorize(ll n) {
    MLL primefactors ;
    if ( n == 1)  return primefactors;
    for ( ll i = 0 ; primes[i] <= sqrt(n) && i < primes.size() ; i++) {
        while (!(n%primes[i])) {
            n = n/primes[i];
            primefactors[primes[i]]++ ;
        }
    }
    if ( n > 1 ) primefactors[n]++ ;
    return primefactors ;
}
MLL factorialfactorization(ll n) {
    MLL factors ;
    if ( n == 1) return factors ;
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
bool vagfol (ll m, ll n) {
    sieve(10000);
    factorsM.clear();
    factorsN.clear() ;
    factorsM = primefactorize(m);
    factorsN = factorialfactorization(n);
    if ( factorsN.size() == 0) return false ;
    else {
        ll f = 0 ;
        ll minimum = inf ;
        for ( auto it = factorsM.begin() ; it != factorsM.end() ; it++) {
            if ( it->second > factorsN[it->first]  ) {
                f = 1 ;
                break ;
            }
            else factorsN[it->first] -= it->second ;
        }
        if (f) return false ;
        else return true ;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (vagfol(15,7)) {
        cout << "POSSIBLE" << endl;
        for ( auto it = factorsN.begin() ; it != factorsN.end() ; it++) {
            if ((it->second)) cout << it->first << " ^ " << it->second << endl; //if power of prime factos is greater than zero we will print it
        }
    }
    else cout << "IMPOSSIBLE" << endl;   
 
    return 0 ;
}
