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

const ll MX = 2e5 + 105;

ll phi(ll n)
{
    double ans = n;
    for(ll i = 2; i*i <= n; i++){
        if(!(n % i)){
            ans -= (ans/(double)i);
            while(!(n % i)) n /= i;
        }
    }
    if(n > 1) ans -= (ans/(double)n);
    return ans;
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        ll a, m;
        cin>>a>>m;

        ll g = gcd(a, m);
        m /= g;
//        error(m, g);
        cout<<phi(m)<<endl;
    }
}
