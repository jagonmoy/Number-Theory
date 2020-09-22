#include <bits/stdc++.h>
using namespace std;
#define sz 1000008
int main() {
    long long low,high;
    vector <long long > primes ;
    vector <long long > vec;
    bool check[sz];
    bool mark[sz];
    //freopen("inputuva.txt","r",stdin);
    while( scanf("%I64d %I64d",&low,&high)!= EOF) {
          long long limit = floor(sqrt(high))+1;
          memset(mark,0,sizeof(mark));
          mark[0] = 1;
          mark[1] = 1;
          for ( long long i = 4 ; i <= limit ; i = i+2)
           mark[i] = 1 ;

          for ( long long i = 3 ; i*i <= limit ; i = i+2) {
            if ( mark[i] == 0) {
                for ( long long j = i*i ; j <= limit ; j = j+i) {
                    mark[j] = 1 ;
                }
            }
          }

          for ( long long i = 1 ; i <= limit ; i++)
            if ( mark[i] == 0) primes.push_back(i);

          if ( primes.size() == 0) printf("There are no adjacent primes.");
          else {
          memset(check,0,sizeof(check));
          long long lolim;
          for ( long long i = 0 ; i < primes.size() ; i++) {
            if (primes[i] < low) {
                if ( low % primes[i] == 0) lolim = low ;
                else lolim = primes[i]*((low/primes[i])+1);
            }
            else lolim = (primes[i]*primes[i]);
            for ( long long j = lolim ; j <= high ; j = j + primes[i]) {
                check[j-low] = 1 ;

            }
          }
            if ( low == 1) check[0] = 1;


           for ( long long i = 0 ; i <= high-low ; i++)
            if ( check[i] != 1) vec.push_back(i+low);


           if ( vec.size() < 2) printf("There are no adjacent primes.");
           else {

           long long maximum = -1 ,minix,miniy,maxx,maxy;
           long long minimum = 3000000000;
           int a1,a2,b1,b2;
           for ( long long i = 1 ; i < vec.size(); i++) {
                if ( vec[i] - vec[i-1] > maximum ) {
                    maximum = vec[i] - vec[i-1];
                    maxx = vec[i-1];
                    maxy = vec[i];

                }

                if ( vec[i] - vec[i-1] < minimum ) {
                    minimum = vec[i] - vec[i-1];
                    minix = vec[i-1];
                    miniy = vec[i];
                }
              }
              a1 = (int)minix;
              a2 = (int)miniy;
              b1 = (int)maxx;
              b2 = (int)maxy;
            printf("%d,%d are closest, %d,%d are most distant.\n",a1,a2,b1,b2);

           }
          }
          primes.clear();
          vec.clear();
    }
    return 0 ;
}
