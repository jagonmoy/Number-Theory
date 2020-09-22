#include <bits/stdc++.h>
using namespace std;

int GCD ( int a, int b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}

int main() {
    int testcase;
    scanf("%d ",&testcase);
    while(testcase--) {
        vector <int> vec;
        int a ;
        string line;
        getline(cin, line);
        istringstream sin(line);
        while ( sin >> a) vec.push_back(a);

        int highest = 0 ;

        for ( int i = 0 ; i < vec.size() ; i++) {
            for ( int j = i + 1 ; j < vec.size() ; j++) {
                int x = GCD(max(vec[i],vec[j]),min(vec[i],vec[j]));
                if ( x >= highest ) highest = x ;
            }
        }

        printf("%d\n",highest);

    }

    return 0 ;
}
