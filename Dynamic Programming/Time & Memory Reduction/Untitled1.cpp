#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 1e3 + 105;
const ll MOD = 100000007;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
//
//ll dp[MX][15005];
//ll cum[MX][15005];
int Case = 1;

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        ll n, f, s;
        cin>>n>>f>>s;

        vector <ll> dp[2], cum[2];
        for(int i = 0; i <= s; i++){
            for(int j = 0; j < 2; j++){
                dp[j].push_back(0);
                cum[j].push_back(0);
            }
        }
        dp[(n+1) & 1][0] = 1;
        cum[(n+1) & 1][0] = 1;
        for(int i = 1; i <= s; i++) cum[(n+1)&1][i] = 1;

        for(int i = n; i >= 1; i--){
            dp[i&1][0] = cum[i&1][0] = 0;
            for(int j = 1; j <= s; j++){

                dp[i&1][j] = cum[(i+1)&1][j-1];
                if(j-f-1 >= 0) dp[i&1][j] = modSub(dp[i&1][j], cum[(i+1)&1][j-f-1]);

                cum[i&1][j] = modAdd(cum[i&1][j-1], dp[i&1][j]);
            }
        }
        cout<<"Case "<<Case++<<": ";
        cout<<dp[1][s]<<endl;
    }
}
