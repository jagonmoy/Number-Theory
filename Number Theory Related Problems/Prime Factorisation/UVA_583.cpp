#include <bits/stdc++.h>
using namespace std;
int main() {

    while(1) {
    long long n ;
    vector < long long > vec ;
    cin >> n ;
    if ( n == 0) break ;
    long long show  = n ;
    long long maxPrime = -1 ;
    if ( n < 0) vec.push_back(-1);
    n = abs(n);
    while ( n % 2 == 0 ) {
        maxPrime = 2 ;
        vec.push_back(2);
        n = n/2;
    }

    for ( long long i = 3 ; i <= sqrt(n) ; i++) {
        while ( n % i == 0) {
            maxPrime = i ;
            vec.push_back(i);
            n = n/i;
        }
    }

    if ( n > 2) {
        maxPrime = n ;
        vec.push_back(n);
    }
    cout << show << " = " ;
    for ( long long i = 0 ; i < vec.size()-1 ; i++) {
        cout << vec[i] << " x " ;
    }
    cout << vec[vec.size()-1] << endl;
    }
    return 0 ;
}
