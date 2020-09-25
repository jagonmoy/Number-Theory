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
ll  check[1000005];
VL primes ;
void sieve(ll n) {
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;   

    for ( ll i = 3 ; i*i <= n ; i += 2) {                
        if (!check[i]) {                               
            for ( ll j = i*i ; j <= n ; j += 2*i) {       
                   check[j] = 1 ;                       
            }                                            
        }                                                
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   
    return  ;
}
VL findingdivisors(ll n) {
    VL divisors ;
    for ( ll i = 1 ; i*i <= n ; i++) {
        if ( n%i == 0 ) {
            divisors.PB(i);
            if ( i != n/i ) divisors.PB(n/i);
        }
    }
    return divisors ;
}
ll euler_phi(ll n) {
    ll result = n ;
    for ( ll i = 0 ; primes[i]*primes[i] <= n && i < primes.size() ; i++) {
        if ( n % primes[i] == 0 ) {
            while(n%primes[i] == 0) n /= primes[i] ;
            result -= result/primes[i] ;
        }
    }
    if ( n > 1) result -= result/n ;
    return result ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    sieve(1000000);
    while(t--) {
        ll n,q ;
        scanf("%lld %lld",&n,&q);
        VL divisors = findingdivisors(n);
        sort(divisors.begin(),divisors.end());
        VL phivec ;
        INC(i,0,divisors.size()-1) phivec.PB(euler_phi(n/divisors[i]));
        INC(i,1,phivec.size()-1) phivec[i] = phivec[i-1]+phivec[i];
        printf("Case %lld\n",++c);
        while(q--) {
            ll a ;
            scanf("%lld",&a);
            if ( a <= 0) printf("0\n");
            else {
                ll up = upper_bound(divisors.begin(),divisors.end(),a)-divisors.begin();
                printf("%lld\n",phivec[up-1]);
            }
        }
    }
    return 0 ;
}
