#include <bits/stdc++.h>
using namespace std;
#define n 1000000
int prime[n+5];
void sieve() {
    prime[0] = 1 ;
    prime[1] = 1 ;
    for ( long long i = 4 ; i <= n ; i = i+2) prime[i] = 1 ;
    for ( long long i = 3 ; i*i <= n ; i = i + 2) {
        if ( prime[i] == 0) {
            for ( long long j = i*i ; j <= n ; j = j + 2*i) {
                prime[j] = 1 ;
            }
        }
    }

    return ;
}
int main() {
    sieve();
    int t ;
    scanf("%d",&t);
    while(t--) {
        int L,U ;
        vector <int > result,shesh ;
        vector < pair<int,int> > baki ;
        scanf("%d %d",&L,&U);
        for ( int i = L ; i <= U ; i++) {
            if ( prime[i] == 0 ) result.push_back(i);
        }
        //for ( int i = 0 ; i < result.size() ; i++) cout << result[i] << " " ;
        //cout << endl;

        for ( int i = 1 ; i < result.size() ; i++) {
            shesh.push_back(result[i]-result[i-1]);
        }
        sort(shesh.begin(),shesh.end());
        //for ( int i = 0 ; i < shesh.size() ; i++) cout << shesh[i] << " " ;

        if ( shesh.size() == 0 ) printf("No jumping champion\n");
        else if ( shesh.size() == 1) printf("The jumping champion is %d\n",shesh[0]);
        else {
        int maximum = -1 ;
        int cnt = 1 ;
        for ( int i = 0 ; i < shesh.size()-1 ; i++) {
            if ( shesh[i] == shesh[i+1]) {
                cnt++ ;
            }
            else {
                if ( cnt >= maximum) {
                    maximum = cnt ;
                    baki.push_back(make_pair(maximum,shesh[i]));
                }
                cnt = 1 ;
            }
        }
        baki.push_back(make_pair(cnt,shesh[shesh.size()-1]));
        sort(baki.begin(),baki.end(),greater< pair<int,int> > ());
        //for ( int i = 0 ; i < baki.size() ; i++) cout << baki[i] << " " ;
        //cout << endl;
        if ( baki[0].first == baki[1].first) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n",baki[0].second);
      }
    }
    return 0 ;
}
