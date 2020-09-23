Explanation : used modular multiplicative inverse , bigmod , prime factoraization .
              if both A and N are co-prime and N itself is a prime then A^(N-1) = 1 (mod N) (Fermat's little theoram ) 
                                                                      => A^(N-2) = A^-1 (mod N) ( dividing both sides by a ) 
                                                                      here A^(N-2) % N is actually modular multiplicative inverse of A. so bigmod(A,N-2) is actually modular 
                                                                      multiplicative inverse of A if N is a  prime .

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
#define eps 1e-9
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
            for ( ll j = i*i ; j <= n ; j += 2*i){       
                   check[j] = 1 ;                        
            }                                            
        }                                                
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   
    return ;
}

MLL primefactorize(ll n) {
    MLL primefactors ;
    for ( ll i = 0 ; primes[i] <= sqrt(n) && i < primes.size() ; i++) {
        while (!(n%primes[i])) {
            n = n/primes[i];
            primefactors[primes[i]]++;
        }
    }

    if ( n > 1) primefactors[n]++;
    return primefactors ;
}
long long  bigmod ( long long a, long long  p)
{
    if ( p == 0 )return 1;
 
    if ( p % 2 )
    {
        return ( ( a % mod ) * ( bigmod ( a, p - 1) ) ) % mod;
    }
    else
    {
        long long c = bigmod(a, p / 2);
        return ( (c%mod) * (c%mod) ) % mod;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(1000000);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        ll n,m ;
        scanf("%lld %lld",&n,&m);
        if ( n == 1 || m == 0) printf("Case %lld: 1\n",++c);
        else {
        MLL factors = primefactorize(n);
        ll sum = 1 ;
        ll f = 0 ;
        for ( auto it = factors.begin() ; it != factors.end() ; it++ ) {
            ll  r = it->first ;
            if ( r%mod == 0) {
                f = 1 ;
                break ;
            }
            ll  p = (it->second)*m ;
            ll s1 = (bigmod(r,p+1)-1)%mod;
            ll s2 = (bigmod(r-1,mod-2))%mod ;    
            ll s = ((s1%mod)*(s2%mod))%mod;
            sum = ((sum%mod)*(s%mod))%mod ;
        }
        if (f) printf("Case %lld: 1\n",++c);
        else printf("Case %lld: %lld\n",++c,sum);
        }
    }
 
    return 0 ;
}
