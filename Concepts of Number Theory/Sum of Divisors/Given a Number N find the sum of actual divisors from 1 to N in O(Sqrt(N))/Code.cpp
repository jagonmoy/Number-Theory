ll findingsumofproperdivisors_1_to_n(ll n) {
    //proper divisors mean except 1 and the number itself all the divisors
    ll ans = 0 ;
    for ( ll i = 2 ; i*i <= n ; i++) {
            ll up = n/i ;
            ans += (up*(up+1))/2 - (i*(i-1))/2 ;
            ans += ((n-(i*i))/i)*i ;
    }
    return ans ;
}
