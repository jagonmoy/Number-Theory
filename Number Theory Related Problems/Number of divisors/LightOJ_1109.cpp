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
VL primes ;
bool compare(const PLL& a, const PLL& b)
{
	if(a.F == b.F)
		return a.S > b.S;

	return a.F < b.F;
}
void sieve(ll n) {
    ll  check[n+5];
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;  

    for ( ll i = 3 ; i*i <= n ; i += 2) {                
        if (!check[i]) {                                
            for ( ll j = i*i ; j <= n ; j += 2*i){       
                   check[j] = 1 ;                        
            }                                            
        }                                                
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   

    return ;
}

ll numberofdivisors(ll n) {
    if ( n == 1) return 1 ;
    ll noofdivisors = 1 ;
    for ( ll i = 0 ;  primes[i] <= sqrt(n) && i < primes.size() ; i++) {
        ll cnt = 0 ;
        while (!(n%primes[i])) {
            n = n/primes[i];
            cnt++ ;
        }
        noofdivisors = noofdivisors*(cnt+1);
    }
    if ( n > 1) noofdivisors = noofdivisors*2;
    return noofdivisors ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    sieve(1000);
    VLL result ;
    INC(i,1,1000) result.PB({numberofdivisors(i),i});
    sort(result.begin(),result.end(),compare);
    scanf("%lld",&t);
    while(t--) {
        ll n ;
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",++c,result[n-1].S);
    }
    return 0 ;
}
