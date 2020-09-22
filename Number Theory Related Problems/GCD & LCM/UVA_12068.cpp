#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}

int main() {
    long long t ;
    scanf("%lld",&t);
    for ( long long z = 1 ; z <= t ; z++ ) {
        long long n,a ;
        scanf("%lld",&n);
        vector <long long > vec ;
        for ( long long i = 0 ; i < n ; i++) {
            scanf("%lld",&a);
            vec.push_back(a);
        }
        long long last = vec[0];
        long long index = 0 ;
        long long result ;
        while( index != vec.size()) {
            result = (vec[index]*last)/GCD(vec[index],last);
            last = result ;
            index++ ;
        }
        long long sum = 0 ;
        for (long long  i = 0 ; i < vec.size() ; i++) {
            sum = sum + (result/vec[i]);
        }
        result = n*result;
        long long divisor = GCD(result,sum);
        printf("Case %lld: %lld/%lld\n",z,result/divisor,sum/divisor);
    }
    return 0 ;

    }
