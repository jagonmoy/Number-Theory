#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}

int main() {

    while(1) {
        int a ;
        scanf("%d",&a);
        if ( a == 0) break ;
        int G = 0 ;
        for ( int i = 1 ; i < a ; i++ ) {
            for ( int j = i+1 ; j <= a ; j++) {
                G = G + GCD(max(i,j),min(i,j));
            }
        }
        printf("%d\n",G);
    }

    return 0 ;
}
