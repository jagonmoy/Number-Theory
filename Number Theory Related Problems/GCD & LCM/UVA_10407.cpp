#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}
int main() {
    while(1) {
        int number ;
        scanf("%d",&number);
        if ( number == 0) break;
        vector <int> vec;
        vec.push_back(number);
        while(1) {
            int num;
            scanf("%d",&num);
            if ( num == 0) break ;
            vec.push_back(num);
        }

        sort(vec.begin(),vec.end());


        for ( int i = 1 ; i < vec.size() ; i++) {
            vec[i] = vec[i] - vec[0] ;
        }
        vec[0] = 0 ;

        int result = 0 ;
        for ( int i = 1 ; i < vec.size() ; i++) {
            result = GCD(max(vec[i],result),min(vec[i],result));
        }

        printf("%d\n",result);
    }
    return 0 ;
}
