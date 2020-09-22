#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        long long number;
        cin >> number ;
        if ( number < 0) break ;
        long long cnt = 0 ;
        if ( number % 2 == 0) {
            while( number % 2 == 0) {
                number = number/2 ;
                cnt++ ;
            }
        }
          if ( cnt ) {for ( long long i = 0 ; i < cnt ; i++) {
            cout << "    2" << endl;
         }
          }

        for ( long long i = 3 ; i <= floor(sqrt(number))+1 ; i = i + 2) {
                cnt = 0 ;
                while( number % i == 0) {
                    number = number/i ;
                    cnt++ ;
                }
                for ( long long  j = 0 ; j < cnt ; j++) cout << "    " << i << endl ;
        }

        if ( number > 2 ) cout << "    " <<  number << endl ;
        printf("\n");
    }

    return 0 ;
}
