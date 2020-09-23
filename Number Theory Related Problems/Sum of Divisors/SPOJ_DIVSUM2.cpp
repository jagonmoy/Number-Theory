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
int status[10000000];
vector<ull> primes2 ;
bool Check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
vector<int> bitwise_sieve(int n)
{
     vector<int> primes ;
     for( int i = 3; i*i <= n; i += 2 ) 
	     if( !Check(status[i/32],i%32)) {
	 	     for( int j = i*i; j <= n; j += 2*i )
			     status[j/32]=Set(status[j/32],j % 32);
		 }

	 primes.PB(2);
	 for(int i=3;i<=n;i+=2) if(!Check(status[i/32],i%32)) primes.PB(i);
     return primes ;
}
ull sumofdivisors(ull n) {
    if ( n == 1) return 1 ;
    ull sod = 1 ;
    for ( ull i = 0 ;  primes2[i] <= sqrt(n) && i < primes2.size() ; i++) {
        if ( n%primes2[i] == 0 && primes2[i] <= n) {
            ull cnt = 0 ;
            ull val = 1 ;
            while (!(n%primes2[i])) {
                n = n/primes2[i];
                cnt = cnt+val;
                val = val*primes2[i];
            }
            sod = sod*(cnt+val); 
        }
    }
    if ( n > 1) sod = sod*(n+1);
    return sod ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes = bitwise_sieve(100000000);
    INC(i,0,primes.size()-1) primes2.PB((ull)primes[i]);
    ull t ;
    scanf("%llu",&t);
    while(t--) {
        ull a ;
        scanf("%llu",&a);
        printf("%llu\n",sumofdivisors(a)-a);
    }
 
    return 0 ;
}
