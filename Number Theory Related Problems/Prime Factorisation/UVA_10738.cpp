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
ll leastprime[1000005];
ll mu[1000005];
ll M[1000005];
void findingleastprime(ll n) {
    leastprime[1] = 1 ; // 1 is the least prime factor of itself ;

    for ( ll i = 2 ; i <= n ; i = i+2 ) leastprime[i] = 2 ; //evey even number's least prime factors is 2

    for ( ll i = 3 ; i <= n ; i = i+2) {
         /* we are checking whether number i has a least prime factor ?
            it it has a least prime factor then all of the multiples of i will
            have the same least prime factor of i . So we don't need to go further .if
            it doesn't have a least prime factor then we will go forward and mark all of it's multiples
            which are not marked earlier will mark them by i  .
         */
        if ( leastprime[i] == 0) {
            leastprime[i] = i ; // the number is a prime that's why it's least prime factor will be the numbers itself
            for ( ll j = i*i ; j <= n ; j = j+i ) {
                if ( leastprime[j] == 0) leastprime[j] = i ; // the number which are not marked earlier by any other small prime number will be marked now .
            }
        }
    }

}
void primefactoraization(ll n) {
    ll val = n ;
    VL primefactors ;
    SL s ;
    while( n!=1) {
        primefactors.PB(leastprime[n]);
        s.insert(leastprime[n]);
        n = n/leastprime[n];
    }
    if ( s.size() != primefactors.size()) mu[val] = 0 ;
    else {
        if ( primefactors.size()%2 == 0) mu[val] = 1;
        else mu[val] = -1;
    }
}
void settingupMarray() {
    INC(i,0,1000000) M[i] = mu[i];
    INC(i,1,1000000) M[i] = M[i] + M[i-1];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(leastprime,0,sizeof(leastprime));
    memset(mu,0,sizeof(mu));
    memset(M,0,sizeof(M));
    mu[1] = 1 ;
    findingleastprime(1000000);    
    INC(i,2,1000000) primefactoraization(i);
    settingupMarray();
    while(1) {
        ll n ;
        scanf("%lld",&n);
        if ( n == 0) break ;
         printf("%8lld%8lld%8lld\n", n, mu[n], M[n]);
    }
 
    return 0 ;
}
