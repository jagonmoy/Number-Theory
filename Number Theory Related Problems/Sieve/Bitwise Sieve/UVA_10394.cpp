#include <bits/stdc++.h>
using namespace std;
#define mx 20000005
int status[mx/4 + 5];
vector <int> primes;
vector < pair <int ,int > > result;

int check(int N , int pos) {
    return (bool)(N &(1 <<pos));
    }
int build ( int N , int pos) {
    return N = (N|(1<<pos));
    }

int main() {
    for (int i = 3 ; i*i <= mx ; i = i+2) {
        if ( check(status[i/32],i%32) == 0) {
            for ( int j = i*i ; j <= mx  ; j = j+i ) {
               status[j/32] = build(status[j/32],j%32);
            }
        }
    }
    primes.push_back(2);

    for ( int i = 3 ; i <= mx ; i = i+2) {
        if ( check(status[i/32],i%32) == 0 ) primes.push_back(i);
    }
    for ( int i = 1 ; i < primes.size() ; i++) {
        if ( primes[i] - primes[i-1] == 2) result.push_back(make_pair(primes[i-1],primes[i]));
    }

    int n ;
    while (scanf("%d",&n) != EOF) {
        printf("(%d, %d)\n",result[n-1].first,result[n-1].second);
    }

    return 0 ;
}
