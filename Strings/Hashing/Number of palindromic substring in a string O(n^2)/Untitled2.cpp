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

const ll MX = 5e3 + 105;

inline void normal(ll &a, ll MOD) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return (a+b)%MOD; }
inline ll modSub(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); a -= b; normal(a, MOD); return a; }
inline ll modPow(ll b, ll p, ll MOD) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b, MOD); b = modMul(b, b, MOD); p >>= 1LL; } return r; }
inline ll modInverse(ll a, ll MOD) { return modPow(a, MOD-2, MOD); }
inline ll modDiv(ll a, ll b, ll MOD) { return modMul(a, modInverse(b, MOD), MOD); }

const ll p1 = 737; ///base 1
const ll p2 = 3079; ///base 2
const ll m1 = 1000000123;
const ll m2 = 1000000321;
vector <pii> prefix_hash;
vector <pii> suffix_hash;
ll pow1[MX];
ll pow2[MX];

void powers()
{
    pow1[0] = 1;
    pow2[0] = 1;
    for(ll i = 1; i < MX; i++){
        pow1[i] = (pow1[i-1]*p1)%m1;
        pow2[i] = (pow2[i-1]*p2)%m2;
    }
}

void pre_Hash(string str)
{
    ll H1 = 0, H2 = 0;
    prefix_hash.clear();
    prefix_hash.push_back({0, 0});
    for(ll i = 0; i < str.size(); i++){
        H1 = (H1 + (str[i] - 'a' + 1)*pow1[i]) % m1;
        H2 = (H2 + (str[i] - 'a' + 1)*pow2[i]) % m2;

        prefix_hash.push_back({H1, H2});
    }

    ll n = str.size()-1;
    suffix_hash.push_back({0, 0});
    H1 = 0, H2 = 0;
    for(ll i = str.size()-1; i >= 0; i--){
        H1 = (H1 + (str[i] - 'a' + 1)*pow1[n-i]) % m1;
        H2 = (H2 + (str[i] - 'a' + 1)*pow2[n-i]) % m2;

        suffix_hash.push_back({H1, H2});
    }
    reverse(suffix_hash.begin(), suffix_hash.end());
}

pii Hash(ll l, ll r, bool flag)
{
    /// Prefix Hash
//    error(l, r, flag);
    if(l > r) return {0, 0};
    if(!flag){
        ll H1 = prefix_hash[r+1].first;
        ll H2 = prefix_hash[l].first;
        ll sub_hash1 = modSub(H1, H2, m1);

        H1 = prefix_hash[r+1].second;
        H2 = prefix_hash[l].second;
        ll sub_hash2 = modSub(H1, H2, m2);

        return {sub_hash1, sub_hash2};
    }
    else{
        ll H1 = suffix_hash[l].first;
        ll H2 = suffix_hash[r+1].first;
        ll sub_hash1 = modSub(H1, H2, m1);

        H1 = suffix_hash[l].second;
        H2 = suffix_hash[r+1].second;
        ll sub_hash2 = modSub(H1, H2, m2);

        return {sub_hash1, sub_hash2};
    }

}

bool palin[MX][MX];

/// Number of palindromic substring in a string O(n^2)

void check_palindromic_substring()
{
    powers();
    string str;
    cin>>str;
    n = str.size();
    pre_Hash(str);
//    for(auto x: prefix_hash) cout<<x.first<<' '<<x.second<<endl;
//    cout<<endl;
//    for(auto x: suffix_hash) cout<<x.first<<' '<<x.second<<endl;
//    cout<<endl;

    ll ans = 0;
    for(ll i = 0; i < str.size(); i++){
        for(ll j = i; j < str.size(); j++){
            ll len = j-i+1;
            if(!(len & 1)){
                ll mid = i+(len/2);

                pii LeftH = Hash(i, mid-1, 0);
                pii RightH = Hash(mid, j, 1);

                RightH.first = (RightH.first * pow1[i]) % m1;
                RightH.second = (RightH.second * pow2[i]) % m2;

                LeftH.first = (LeftH.first * pow1[n-j-1]) % m1;
                LeftH.second = (LeftH.second * pow2[n-j-1]) % m2;

                if(RightH == LeftH){
                    palin[i][j] = 1;
                    ans++;
                }
            }
            else{
                ll mid = i+(len/2);

                pii LeftH = Hash(i, mid-1, 0);
                pii RightH = Hash(mid+1, j, 1);

                RightH.first = (RightH.first * pow1[i]) % m1;
                RightH.second = (RightH.second * pow2[i]) % m2;

                LeftH.first = (LeftH.first * pow1[n-j-1]) % m1;
                LeftH.second = (LeftH.second * pow2[n-j-1]) % m2;

                if(RightH == LeftH){
                    palin[i][j] = 1;
                    ans++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            error(i, j, palin[i][j]);
        }
    }
}

int main()
{
    optimize
    check_palindromic_substring();
}
