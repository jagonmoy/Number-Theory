#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        long long number;
        scanf("%lld",&number);
        if ( number == 0) break;
        if ( number == 1) printf("0\n");
        else {
        long long ret = number ;
        for ( long long i = 2 ; i*i <= number ; i++) {
            if ( number % i == 0) {
                while(number % i == 0) {
                    number = number/ i;
                }
                    ret = ret - (ret/i);
            }
        }
        if ( number > 1) ret = ret - (ret/number);
        printf("%lld\n",ret);
        }
    }

    return 0 ;
}
