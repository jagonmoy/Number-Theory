#include <bits/stdc++.h>
using namespace std;
#define mx 1000000
int check( int N , int pos) {
    return (bool)(N&(1 << pos));
}
int build ( int N, int pos) {
    return N=(N|(1<<pos));
}
int main() {
        int mark[mx/4+5];
        vector < int > primes;
        for ( int i= 3 ; i*i <= mx ; i = i+2) {
            if ( check(mark[i/32],i%32) == 0) {
                for ( int j = i*i ; j <= mx ; j = j+i) {
                    mark[j/32] = build(mark[j/32],j%32) ;
                }
            }
        }

        primes.push_back(2);
        for ( int i = 3 ; i <= mx ; i = i+2)
            if ( check(mark[i/32],i%32) == 0) primes.push_back(i);


        while(1) {
        int a ;
        scanf("%d",&a);
        if ( a == 0) break;
        int result = a ;
        int divisors = 0 ;

        for ( int i = 0 ; i < primes.size() ; i++) {
            if ( a % primes[i] == 0) {
                divisors++ ;
                while( a % primes[i] == 0) {
                    a = a / primes[i];
                }
            }
        }
        printf("%d : %d\n",result,divisors);

    }

    return 0 ;
}
