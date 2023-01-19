#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <ll, ll>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 1e6 + 105;

const ll p1 = 737; ///base 1
const ll p2 = 3079; ///base 2
const ll m1 = 1000000123;
const ll m2 = 1000000321;

inline void normal(ll &a, ll MOD) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a+b)%MOD; }
inline ll modSub(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); a -= b; normal(a, MOD); return a; }
inline ll modPow(ll b, ll p, ll MOD) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b, MOD); b = modMul(b, b, MOD); p >>= 1LL; } return r; }
inline ll modInverse(ll a, ll MOD) { return modPow(a, MOD-2, MOD); }
inline ll modDiv(ll a, ll b, ll MOD) { return modMul(a, modInverse(b, MOD), MOD); }

vector <pii> prefix_hash;
ll pow1[MX];
ll pow2[MX];

/// Robin-Karp pattern matching algorithm

void Hash(string str)
{
    ll H1 = 0, H2 = 0;
    prefix_hash.clear();
    prefix_hash.push_back({0, 0});
    for(int i = 0; i < str.size(); i++){
        H1 = (H1 + (str[i] - 'a' + 1)*pow1[i]) % m1;
        H2 = (H2 + (str[i] - 'a' + 1)*pow2[i]) % m2;

        prefix_hash.push_back({H1, H2});
    }
}
pair <ll, ll> Hash1(string str)
{
    ll H1 = 0, H2 = 0;
    for(int i = 0; i < str.size(); i++){
        H1 = (H1 + (str[i] - 'a' + 1)*pow1[i]) % m1;
        H2 = (H2 + (str[i] - 'a' + 1)*pow2[i]) % m2;
    }
    return {H1, H2};
}

void powers()
{
    pow1[0] = 1;
    pow2[0] = 1;
    for(int i = 1; i <= 1e6; i++){
        pow1[i] = (pow1[i-1] * p1) % m1;
        pow2[i] = (pow2[i-1] * p2) % m2;
    }
}

void solve()
{
    string text, pattern;
    ll n;
    cin>>n;
    cin>>pattern;
    cin>>text;

    Hash(text);
    pii hval = Hash1(pattern);

    vector <int> ans;
    for(int i = 0; i+pattern.size()-1 < text.size(); i++){
        int j = i+pattern.size()-1;

        ll H1 = prefix_hash[j+1].first;
        ll H2 = prefix_hash[i].first;
        ll sub_hash = modSub(H1, H2, m1);
        ll x = modMul(hval.first, pow1[i], m1);

        if(sub_hash != x) continue;

        H1 = prefix_hash[j+1].second;
        H2 = prefix_hash[i].second;
        sub_hash = modSub(H1, H2, m2);
        x = modMul(hval.second, pow2[i], m2);

        if(sub_hash != x) continue;
        ans.push_back(i);
    }
    for(auto x: ans) cout<<x<<endl;
    if(!ans.size()) cout<<endl;
}

int main()
{
    optimize
    powers();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
