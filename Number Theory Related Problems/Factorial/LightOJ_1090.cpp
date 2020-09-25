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
ll leastprime[1000005];

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

MLL primefactoraization(ll n) {
    MLL primefactors ;
    while( n!=1) {
        primefactors[leastprime[n]]++;
        n = n/leastprime[n];
    }
    return primefactors ;
}

ll factorialpower(ll n,ll p) {
    ll freq = 0 ;
    while(n) {
        freq += n/p;
        n = n/p;
    } 
    return freq ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    findingleastprime(1000000);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        ll n,r,p,q ;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ll sumtwo = factorialpower(n,2);
        sumtwo -= factorialpower(r,2);
        sumtwo -= factorialpower(n-r,2);
        ll sumfive = factorialpower(n,5);
        sumfive -= factorialpower(r,5);
        sumfive -= factorialpower(n-r,5);
        MLL factors = primefactoraization(p);
        sumtwo += factors[2]*q ;
        sumfive += factors[5]*q;
        printf("Case %lld: %lld\n",++c,min(sumtwo,sumfive));       
    }
 
    return 0 ;
}
