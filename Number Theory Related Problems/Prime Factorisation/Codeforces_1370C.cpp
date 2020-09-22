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
VL sieve(ll n) {
    ll  check[n+5];
    VL primes ;
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
    return primes ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    VL primes = sieve(100000);
    while(t--) {
        ll n ;
        cin >> n ;
        if ( n % 2 == 1){
           if ( n == 1) cout << "FastestFinger" << endl;
           else cout << "Ashishgup" << endl;
        }
        else {
            ll odd = 0 ;
            ll even = 0 ;
            for ( ll i = 0 ; primes[i] <= sqrt(n) && i < primes.size() ; i++) {
                 while (!(n%primes[i])) {
                    n = n/primes[i];
                    if ( primes[i]%2 == 1) odd++;
                    else even++ ;
                }
            }
            if ( n > 1) odd++ ;
            
            if ( odd == 0 && even == 1) cout << "Ashishgup" << endl;
            else if ( odd == 0 && even > 1) cout << "FastestFinger" << endl;
            else if ( odd == 1 && even == 1)  cout << "FastestFinger" << endl;
            else if ( odd == 1 && even > 1) cout << "Ashishgup" << endl;
            else  cout << "Ashishgup" << endl;
        }
    }
 
    return 0 ;
}
