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

const ll MX = 2e5 + 5;
ll ara[MX];

int main()
{
    optimize
    ll n;
    cin>>n;
    double N = n-1;

    double nthRoot=ceil(pow(1e9, 1.0/N));

    ll till = (ll)nthRoot;
    cout<<till<<endl;
    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }
    sort(ara, ara+n);
//    cout<<pow(1e18, 1.0/(n-1))<<endl;

    ll ans = -1;
    for(ll i = 1; i <= till; i++){
        ll cur = 0;
        for(ll j = 0; j < n; j++){
            if(i == till) cout<<i<<' '<<j<<' '<<pow(i, j)<<endl;
            ll x = ceil(pow(i, j));
            cur += abs(ara[j]-x);
        }
        if(ans == -1 || ans > cur) ans = cur;
    }
    cout<<ans<<endl;
}
