#include <bits/stdc++.h>
using namespace std;
#define MX 90
#define RESET(ara, b) memset(ara, b, sizeof(ara))
typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

vector <ll> digits;
ll dp[40][2][2];

ll solve(ll n, bool f1, bool prev)
{
    if(n == digits.size()){
        return 0;
    }

    ll &res = dp[n][f1][prev];
    if(res != -1){
        return res;
    }

    ll ans = 0;
    ll k = f1 ? 1 : digits[n];

    for(int i = 0; i <= k; i++){
        ll cur = solve(n+1, i < digits[n] ? 1 : f1, i);
        if(i == 1 && prev == 1) ans++;
    }
    error(n, f1, prev, ans);
    return res = ans;
}

int main()
{
    ll T;
    scanf("%lld", &T);

    for(int t = 1; t <= T; t++){
        ll n;
        cin>>n;
        digits.clear();
        RESET(dp, -1);

        while(n){
            digits.push_back(n&1);
            n = (n>>1);
        }
        reverse(digits.begin(), digits.end());
        ll ans1 = solve(0, 0, 0);

        printf("Case %d: %lld\n", t, ans1);
    }
    return 0;
}
