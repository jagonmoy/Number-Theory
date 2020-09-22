#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        long long n ;
        scanf("%lld",&n);
        if ( n == 0) break;
        if ( n < 0) n = abs(n);
        long long number = n ;
        long long cnt = 0 ;
        long long result;
        if ( n % 2 == 0) {
        while ( n % 2 == 0) {
            n = n/2 ;
        }
        cnt++;
        }
        //if ( n == 1) printf("-1\n");
        //else
        if ( n != -1) {
            for ( long long i = 3 ; i*i <= number ; i = i+2) {
                if ( n % i == 0) {
                while ( n % i == 0) {
                    n = n/i ;
                }
                result = i ;
                cnt++ ;
            }
        }
        if ( n > 2) cnt++ ;
        }

        if ( cnt <= 1) printf("-1\n");
        else {
            if ( n > 2) printf("%lld\n",n);
            else printf("%lld\n",result);
        }

        //if ( n > 2 && cnt >= 1 ) printf("%I64d\n",n);
        //else if ( n == 1 && cnt >= 2) printf("%I64d\n",result);
        //else if ( n == 1 && cnt == 1) printf("-1\n");
        //else if ( number == n) printf("-1\n");
        //}
      }

    return 0 ;
}
