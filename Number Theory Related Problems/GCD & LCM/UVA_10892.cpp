#include <bits/stdc++.h>
using namespace std;
int GCD( int a , int b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
    }
int main() {
    while(1) {
        long long number;
        scanf("%lld",&number);
        if ( number == 0) break ;
        vector < long long > divisors;
        long long kaj = number;
        for ( long long  i = 1 ; i <= floor(sqrt(number)) ; i++) {
            if ( number % i == 0) {
                if (number/i == i) {
                    divisors.push_back(i);
                }
                else {
                        divisors.push_back(i);
                        divisors.push_back(number/i);
            }

        }
    }
    //for ( int i = 0 ; i < divisors.size() ; i++) cout << divisors[i] << " ";
    //cout << endl;

    long long cnt = 0 ;
    for ( long long i = 0 ; i < divisors.size() ; i++) {
        for ( long long j = i ; j < divisors.size() ; j++) {
                long long  result = (divisors[i]*divisors[j])/GCD( max(divisors[i],divisors[j]),min(divisors[i],divisors[j]));
                if ( result == kaj ) cnt++ ;
        }
    }
    printf("%lld %lld\n",kaj,cnt);
    }
    return 0 ;
}
