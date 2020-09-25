
/*
Explanation : 
To get the trailling zeroes , we divide the power of each prime factor by the power of corresponding prime factor presented in base . then by iterating over 
all the prime factors of base we take the minimum result of the division . Here in this problem we just did the opposite thing . because we were asked to do what will be the 
maximum zeroes if minimum  t trailing zeroes are there . so , in this problem we iterated over all the prime factors of factorial and divider their power by t and then 
for each prime factor we did ,  pi^(pow/t) , here pi means the i indexed prime factors ,pow means it's power and t means the needed trailling zero .
so the result will be product of all the pi = pi^(pow/t) . this power is too large so calculate it we used bigmod .
so there are actually 3 steps.
1 .precalculate sieve
2. prime factorise the given n 
3. divide power of each prime factor by it and multiply primefactor^(power/t) to the result every time . */


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
#define mod  10000019
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
ll  check[100005];
VL primes ;
void sieve(ll n) {
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;    //the numbers which are not prime that means even numbers are marked by 1

    for ( ll i = 3 ; i*i <= n ; i += 2) {                // Even numbers are not prime so we will check only odd numbers and increment the number by 2 to avoid even number.
        if (!check[i]) {                                 // if  check[i] = 0 that means if the i value is a prime we will procced
            for ( ll j = i*i ; j <= n ; j += 2*i){       // here we are starting not by j = i+i we are starting by j = i*i because the numbers less than i*i are already 
                   check[j] = 1 ;                        // checked by the numbers less than j so no need to calculate them further . and each time we will increment the
            }                                            // numbers by 2*i because if this is a odd number then just incrementing i it will be even and even numbers 
        }                                                // numbers are not prime so no need to check this .
    }   

    for ( ll i = 1 ; i <= n ; i++)  if (!check[i]) primes.PB(i);   // only taking the primes numbers in vector
    return ;
}
MLL factorialfactorization(ll n) {
    MLL factors ;
    for ( ll i = 0 ; primes[i] <= n && i < primes.size() ; i++) {
        ll freq = 0 ;
        ll x = n ;
        while(x) {
            freq += x/primes[i];
            x = x/primes[i];
        }
        if ( freq != 0) factors[primes[i]] = freq ; 
    }
    return factors ;
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
    ll t,c = 0 ;
    sieve(100000);
    scanf("%lld",&t);
    while(t--) {
        ll n,k ;
        scanf("%lld %lld",&n,&k);   
        MLL m = factorialfactorization(n);
        ll result = 1 ;
        ll f = 0 ;
        for ( auto it = m.begin() ; it != m.end() ; it++) {
            //printf("%lld %lld\n",it->first,it->second);
            ll pow = (it->second)/k ;
            if ( pow > 0) f = 1 ;
            if ( pow > 0 ) {
                ll val = bigmod(it->first,pow);
                //printf("%lld\n",val);
                result = ((result%mod)*(val%mod))%mod ;
            }
        }
        if (f) printf("Case %lld: %lld\n",++c,result);
        else printf("Case %lld: -1\n",++c,result);
    }
 
    return 0 ;
}
