VL phi_1_to_n(ll n) {
    VL phi(n + 5,0);
    phi[0] = 0;
    phi[1] = 1;
    INC(i,2,n) phi[i] = i;

    for ( ll i = 2 ; i <= n ; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi ;
}
