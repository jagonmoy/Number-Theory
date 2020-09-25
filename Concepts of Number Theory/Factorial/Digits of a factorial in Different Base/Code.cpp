ll  digits_of_n_factorial_in_b_base( ll n, ll b) {
    double x = 0;
    for ( ll i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(b); // Base Conversion
    }
    ll res = x + 1 + eps;
    return res;
}
