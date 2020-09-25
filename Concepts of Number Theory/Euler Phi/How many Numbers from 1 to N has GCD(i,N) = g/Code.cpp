  
ull phi[1000005];
void phi_1_to_n(ll n) {
    phi[0] = 0;
    phi[1] = 1;
    INC(i,2,n) phi[i] = i;

    for ( ull i = 2 ; i <= n ; i++) {
        if (phi[i] == i) {
            for (ull j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return ;
}
ll  from_1_to_n_number_of_numbers_equals_to_gcd_with_n_equals_to_g(ull n,ull g) {
    return phi[n/g] ;
}
