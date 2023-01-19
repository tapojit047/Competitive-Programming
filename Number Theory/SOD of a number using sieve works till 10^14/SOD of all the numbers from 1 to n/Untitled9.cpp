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

int Case = 1;
ll sum(ll n)
{
    return n*(n+1)/2;
}

ll SOD_1_to_n(ll n)
{
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        ll p = n/i;
        ans += p*i;

        if(p > sqrt(n)){
            ll x = sqrt(n);
            ans += sum(p)-sum(x);
        }
    }
    return ans;
}

/// https://www.programmersought.com/article/16295928148/
/// SUM of all the divisors of all the numbers from 1 to n in O(sqrt(n))

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<"Case "<<Case++<<": ";
        cout<<SOD_1_to_n(n)<<endl;
    }
}
