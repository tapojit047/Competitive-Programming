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

const ll MX = 1e6 + 105;
const ll MOD = 1e7 + 7;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll sum[MX];
bool chk[MX];
ll power[MX];
vector <int> prime;
void sieve(int n)
{
    int i, j;
    chk[1] = 1;
    for(i = 4; i <= n; i += 2) chk[i] = 1;
    for(i = 3; ll(i)*ll(i) <= ll(n); i++){
        if(chk[i]) continue;
        for(j = i*i; j <= n; j += i) chk[j] = 1;
    }
    for(int i = 2; i <= n; i++) if(!chk[i]) prime.pb(i);
    ///O(n*log2(log2(n))
}


vector <pii> primediv;
void factorize(int n)
{
    for(int j = 0; j < prime.size(); j++){
        if(prime[j]*prime[j] > n) break;
        if(n % prime[j] == 0){
            int c = 0;
            while(n % prime[j] == 0) n /= prime[j], c++;
            primediv.push_back({prime[j], c});

        }
    }
    if(n > 1) primediv.push_back({n, 1});
    ///O(log2(n))
}

int main()
{
    optimize
    sieve(1e6);

    sum[1] = 1;
    for(int i = 2; i <= 1e6; i++){
        primediv.clear();
        factorize(i);
//        error(i, primediv.size());
        ll cur = sum[i-1];
        for(auto x: primediv){
            int num = x.first;
            int p = x.second;

            cur = modDiv(cur, power[num]+1);
            power[num] += p;
            cur = modDiv(cur, p+1);
        }
        sum[i] = cur;
    }

//    int t;
//    cin>>t;
//    while(t--){
//        int x;
//        cin>>x;
//        cout<<sum[x]<<endl;
//    }
}
