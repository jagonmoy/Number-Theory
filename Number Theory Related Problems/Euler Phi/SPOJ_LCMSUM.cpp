#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define mod  1000000007
typedef ostringstream OS ;
typedef stringstream SS ;
typedef long long ll ;
typedef unsigned long long ull;
typedef pair < ll , ll > PLL ;
typedef pair < char,ll > PCL ;
typedef deque < double > DD ;
typedef deque < PCL > DCL ;
typedef deque < ll > DL ;
typedef deque < PLL > DLL ;
typedef deque < char > DC ;
typedef deque < string > DS ;
typedef vector < double > VD;
typedef vector < PCL > VCL ;
typedef vector < ll > VL;
typedef vector < PLL > VLL ;
typedef vector < char > VC ;
typedef vector < string > VS ;
typedef map < ll ,ll > MLL ;
typedef map < char,ll > MCL;
typedef map < ll,char > MLC;
typedef map < string,ll> MSL;
typedef priority_queue < PLL > PQLL ;
typedef priority_queue < ll > PQL ;
typedef stack < ll > SKL ;
typedef stack < PLL > SKLL ;
typedef queue < ll > QL ;
typedef queue < PLL > QLL ;
typedef set < ll > SL ;
typedef set < PLL > SLL ;
typedef set < char > SC ;
 
string numtostr(ll n) {
     OS str1 ;
     str1 << n ;
     return str1.str();
}
ll strtonum(string s) {
     ll x ;
     SS str1(s);
     str1 >> x ;
     return x ;
}
ll GCD(ll a, ll b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}
ll LCM(ll a , ll b) {
    ll gcd = GCD(a,b);
     return (a/gcd)*b ;
}

ull phi[1000005];
ull sum[1000005];

void phi_1_to_n(ll n) {
    phi[0] = 0;
    phi[1] = 1;
    INC(i,2,n) phi[i] = i;

    for ( ull i = 2 ; i <= n ; i++) {
        if (phi[i] == i) {
            for (ull j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return ;
}
void  summing_1_to_n(ull n) {
    for ( ull i = 1 ; i <= n ; i++) {
        for ( ull j = i ; j <= n ; j += i) {
            sum [j] += phi[i]*i ;
        }
    }
    return  ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    phi_1_to_n(1000000);
    summing_1_to_n(1000000);
    ull t ;
    scanf("%llu",&t);
    while(t--) {
        ull n ;
        scanf("%llu",&n);
        ull ans = sum[n];
        ans = (ans+1)*n;
        ans = ans/2 ;
        printf("%llu\n",ans);
    }
 
    return 0 ;
}
