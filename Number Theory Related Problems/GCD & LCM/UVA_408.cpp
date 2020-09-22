#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}

int main() {
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF ) {
        int x = GCD(max(a,b),min(a,b));
        if ( x == 1 ) {
            printf("%10d%10d     Good Choice\n\n",a,b);
        }
        else printf("%10d%10d     Bad Choice\n\n",a,b);
    }
    return 0;
}
