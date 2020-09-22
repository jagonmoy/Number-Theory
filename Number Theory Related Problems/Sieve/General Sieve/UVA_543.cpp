#include <bits/stdc++.h>
using namespace std;
#define sz 1000007
int main() {
    int n ;
    while(1) {
    scanf("%d",&n);
    if ( n == 0) break ;
    bool marked[sz];
    marked[0] = 1 ;
    marked[1] = 1;
    marked[2] = 0 ;
    for ( int i = 4 ; i <= n ; i = i+2)
        marked[i] = 1 ;

    for ( int i = 3 ; i*i <= n ; i = i+2 ) {
        if ( marked[i] == 0 ) {
            for ( int j = i*i ; j <= n ; j = j+i+i) {
                marked[j] = 1 ;
            }
        }
    }
    int x = -1 , y = -1 ;

    for ( int i = 2 ; i*i <= n ; i++) {
        if ( marked[i] == 0 && marked[n-i] == 0 ) {
            x = i ;
            y = n-i;
            break ;
        }
    }

    if ( x == -1 && y == -1) printf("Goldbach's conjecture is wrong.\n");
    else printf("%d = %d + %d\n",n,x,y);
    }

    return 0 ;
}
