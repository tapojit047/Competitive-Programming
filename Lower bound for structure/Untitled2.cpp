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
#define pii pair <int, int>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

ll dp[MX];
ll n;
ll Next[MX];

struct tapo
{
    ll s, e, m;
};
tapo ara[MX];

bool comp(tapo a, tapo b)
{
    return a.s < b.s;
}

ll func(int pos)
{
    ll &res = dp[pos];
    if(res != -1) return res;
    if(pos == n) return 0;

    res = 0;
    res = func(pos+1);
    res = max(res, ara[pos].m + func(Next[pos]));
    return res;
}

int main()
{
    optimize
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ara[i].s>>ara[i].e>>ara[i].m;
    }
    sort(ara, ara+n, comp);

    for(ll i = 0; i < n; i++){
        tapo x;
        x.s = ara[i].e+1;
        ///searching it using comp for ara[i].s
        ll l = lower_bound(ara, ara+n, x, comp)-ara;
        Next[i] = l;
    }

    RESET(dp, -1);
    cout<<func(0)<<endl;
}
