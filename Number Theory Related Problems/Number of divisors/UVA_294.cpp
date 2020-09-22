#include <bits/stdc++.h>
using namespace std;
int main() {
    int testcase;
    scanf("%d",&testcase);
    while(testcase--) {
        long long low,up;
        scanf("%lld %lld",&low,&up);

        long long result,songkha;
        long long  highest = -1;
        for ( long long i = low ; i <= up ; i++) {
            vector <long long > primes;
            long long y = i ;
            long long z = i ;
          //  cout << y << " " << z << endl;
            long long x = floor(sqrt(y))+1;
            //cout << x << endl;
            bool mark[x+5];
            memset(mark,0,sizeof(mark));

            for ( long long i = 4 ; i <= x ; i = i+2) mark[i] = 1 ;

            mark[1] = 1 ;
            mark[0] = 1 ;
            mark[2] = 0 ;

            for ( long long i = 3 ; i*i <= x ; i = i+2) {
                if ( mark[i] == 0) {
                    for ( long long j = i*i ; j <= x ; j = j + i ) {
                        mark[j] = 1 ;
                }
            }
        }


        for ( long long i = 2 ; i <= x ; i++)
            if ( mark[i] == 0) primes.push_back(i);

        //for ( int i = 0 ; i < primes.size() ; i++) cout << primes[i] << " " ;
        //cout << endl;


        long long divisors = 1 ;
        for ( long long i = 0 ; i < primes.size() ; i++) {
            if ( y % primes[i] == 0) {
            long long  cnt = 1 ;
            while( y % primes[i] == 0) {
                y = y/primes[i];
                cnt++;
            }
            divisors = divisors*cnt;
         }
        }

        if ( y > 2) divisors = divisors*2;

        //cout << divisors << endl;

        if ( divisors > highest) {
            result = z ;
            songkha = divisors;
            highest = divisors;
        }

    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",low,up,result,songkha);
    }
    return 0 ;
}
