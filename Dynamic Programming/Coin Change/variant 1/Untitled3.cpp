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
#define pii pair <ll, ll>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

int main()
{
    optimize
    ll t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;

        if(y >= x) y = x;

        ll ans = 0;
        bool first = 1;
        while(1){
            ll p = (x/y);
            ll q = (x/p);
            ll r = (x/(p+1));

            if(q*q <= x){
                ans += q*(q-1)/2;
                break;
            }
            ll cur = (y-r-1)*(p);
            if(y == q) cur += p-1;
            else cur += p;
//            error(p, q, r, x, y, cur);
            ans += cur;
//            if(q-y == 1) ans++;
            y = r;
        }
        cout<<ans<<endl;
    }
}
