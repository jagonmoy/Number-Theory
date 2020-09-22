#include <bits/stdc++.h>
using namespace std;
#define n 10000000
int prime[n+5];
void sieve() {
    prime[0] = 1 ;
    prime[1] = 1 ;
    for ( int i = 4 ; i <= n ; i = i+2) prime[i] = 1 ;
    for ( int i = 3 ; i*i <= n ; i = i + 2) {
        if ( prime[i] == 0) {
            for ( int j = i*i ; j <= n ; j = j + 2*i) {
                prime[j] = 1 ;
            }
        }
    }

    return ;
}

int main() {
    sieve();
    int a ;
    while(scanf("%d",&a) != EOF) {
        int shuru = a ;
        vector < int> vec ;
        int baki = 0 ;


        for (int i = a  ; i >= 0 ; i-- ) {
            if ( prime[i] == 0 && prime[a-i] == 1 && a-i >= 6) {
                baki = i ;
                vec.push_back(baki);
                break ;
            }
        }

        a = a - baki ;
        for (int i = a ; i >= 0 ; i-- ) {
            if ( prime[i] == 0 && prime[a-i] == 1 && a-i >= 4 ) {
                baki = i ;
                vec.push_back(baki);
                break ;
            }
        }

        a = a - baki ;
        for ( int i = a ; i >= 0 ; i--) {
            if ( prime[i] == 0 && prime[a - i] == 0 ) {
                vec.push_back(i);
                vec.push_back(a-i);
                break ;
                }
            }

        int total = 0 ;
        for ( int i = 0 ; i < vec.size() ; i++) total = total + vec[i] ;

        if ( total == shuru && vec.size() == 4 ) {
        for ( int  i = 0 ; i < vec.size()-1 ; i++) printf("%d ",vec[i]);
        printf("%d\n",vec[vec.size()-1]) ;
        }
        else printf("Impossible.\n");
    }

    return 0 ;

    }
