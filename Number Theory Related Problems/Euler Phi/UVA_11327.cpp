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
VL phi(5000005,0);
VL range ;
void phi_1_to_n(ull n) {
    range.PB(0);
    phi[0] = 1;
    phi[1] = 1;
    INC(i,2,n) phi[i] = i;

    for ( ull i = 2 ; i <= n ; i++) {
        if (phi[i] == i) {
            for (ull j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    INC(i,1,n) phi[i] = phi[i] + phi[i-1];
    return  ;
}
 
int main() {
    phi_1_to_n(2000005);
    while(1) {
        ull a ;
        scanf("%llu",&a);
        if ( a == 0) break ;
        if ( a == 1) printf("0/1\n");
        else if ( a == 2) printf("1/1\n");
        else {
            ull low = upper_bound(phi.begin(),phi.begin()+300000,a)-phi.begin() ;
            ull rem = a - phi[low-1];
            if ( rem == 0 ) printf("%llu/%llu\n",low-2,low-1);
            else {
                ull ans ;
                for ( ll i = 1 ; i <= low ; i++) {
                    if ( GCD(i,low) == 1){
                        ans = i ;
                        rem-- ;
                    }
                if ( rem == 0) break ;
                }
                printf("%llu/%llu\n",ans,low);
            }
        }
    }
    return 0 ;
}
