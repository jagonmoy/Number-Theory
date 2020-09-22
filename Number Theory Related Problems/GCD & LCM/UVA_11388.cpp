#include <bits/stdc++.h>
using namespace std;
int main() {
    int t ;
    scanf("%d",&t);
    while(t--) {
        int G,L ;
        scanf("%d %d",&G,&L);
        if ( L % G == 0) printf("%d %d\n",G,L);
        else printf("-1\n");
        }
    return 0 ;
}
