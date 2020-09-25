#include <bits/stdc++.h>
using namespace std;
int main() {
    int number;
    while(scanf("%d",&number) != EOF ) {
        int divisorNumber = number ;
        int divisors = 1 ;
        for ( int i = 2 ; i <= divisorNumber/i ; i++) {
            if ( divisorNumber % i == 0 ) {
                int cnt = 1 ;
                while ( divisorNumber % i == 0) {
                    divisorNumber = divisorNumber/i ;
                    cnt++ ;
                }
            divisors = divisors*cnt ;
            }
        }
        if ( divisorNumber > 1) divisors = divisors*2 ;

        int eulerNumber = number ;
        int result = number ;
        for ( int i = 2 ; i <= number/i ; i++) {
            if ( number % i == 0) {
                while( number % i == 0) {
                    number = number / i ;
                }
                eulerNumber = eulerNumber - ( eulerNumber/i);
            }
        }
        if ( number > 1 ) eulerNumber = eulerNumber - ( eulerNumber/number);
        printf("%d\n",result - eulerNumber - divisors+1);
    }
    return 0 ;
}
