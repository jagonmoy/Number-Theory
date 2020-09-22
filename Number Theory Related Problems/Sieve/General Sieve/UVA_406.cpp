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
  
ll  check[1005];
VL primes ;
ll primecount[1005];
void sieve(ll n) {
    memset(check,0,sizeof(check));
    check[1] = 0 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;

    for ( ll i = 3 ; i*i <= n ; i += 2) {             
        if (!check[i]) {                                
            for ( ll j = i*i ; j <= n ; j += 2*i){     
                   check[j] = 1 ;                      
            }                                             
        }                                                
    }   
    ll primecnt = 0 ;
    for ( ll i = 1 ; i <= n ; i++)  {
        if (!check[i]) {
            primes.PB(i); 
            primecnt++ ;
       }
       primecount[i] = primecnt;  
    }
    return ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(1000);
    ll n,c ;
    while(scanf("%lld %lld",&n,&c) == 2) {
        printf("%lld %lld: ",n,c);
        if ( primecount[n]%2 == 0) c = 2*c ;
        else c = 2*c-1;
        if ( c > primecount[n]) {
            INC(i,1,primecount[n]-1) printf("%lld ",primes[i-1]);
            printf("%lld\n",primes[primecount[n]-1]);
        }
        else {
            ll start = ((primecount[n]-c)/2);
            INC(i,start,start+c-2) printf("%lld ",primes[i]);
            printf("%lld\n",primes[start+c-1]);
        }
        printf("\n");
    }
 
    return 0 ;
}
