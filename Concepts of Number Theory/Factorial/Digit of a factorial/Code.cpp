ll digit_of_a_factorial(ll n) {
    double x = 0 ;
    INC(i,1,n) {
        x += log10(i);
    }
    x = x+1+eps ;
    return (ll)x ;
}
