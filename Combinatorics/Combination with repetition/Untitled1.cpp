#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)


#define        MOD        1000000007

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define        MX        200005

ll CombinationWithRepetition(ll n, ll k)
{
    ///Number of ways taking K elements from N elements while choosing an element more than once
    ll ans = 1;
    for(ll i = 1; i <= n+k-1; i++){
        ans = modMul(ans, i);
    }
    for(ll i = 1; i <= k; i++){
        ans = modDiv(ans, i);
    }
    for(ll i = 1; i <= n-1; i++){
        ans = modDiv(ans, i);
    }
    return ans;
}
int main()
{
    optimize
    ll n, m;
    cin>>n>>m;
    cout<<CombinationWithRepetition(n, m)<<endl;
}
