#include <bits/stdc++.h>
using namespace std;
#define sz 100000
int main() {
    while(1) {
    int n ;
    scanf("%d",&n);
    if ( n == 0) break;
    bool mark[sz];
    memset(mark,0,sizeof(mark));
    mark[0] = 1 ;
    mark[1] = 1 ;
    mark[2] = 0 ;
    for ( int i = 4 ; i <= n ; i = i+2)
        mark[i] = 1 ;

    for ( int i = 3 ; i*i <= n ; i = i+2) {
        if ( mark[i] == 0) {
                for ( int j = i*i ; j <= n ; j = j+i) {
                    mark[j] = 1 ;
                }
        }
    }

    int hishab = 0 ;
    for ( int i = 2 ; i <= n ; i++) {
        if ( mark[i] == 0 && mark[n-i] == 0) {
            mark[i] = 1 ;
            mark[n-i] = 1 ;
            hishab++ ;
        }
    }

    printf("%d\n",hishab);
    }
    return 0 ;
}
