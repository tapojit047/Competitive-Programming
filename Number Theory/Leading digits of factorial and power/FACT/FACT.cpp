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

/// Leading digits of factorial of n
/// https://forthright48.com/leading-digits-of-factorial

const double eps = 1e-9;

ll leadingDigitsPow(ll n, ll k)
{
    double fact = 0;
    for(ll i = 1; i <= n; i++){
        fact += log10(i);
    }
    double lg = fact-floor(fact+eps);

    double B = pow(10, lg);

    for(ll i = 1; i < k; i++){
        B *= 10;
    }
    return (floor(B+eps));
}

int main()
{
    optimize
    ll n, k;
    cin>>n>>k;

    cout<<leadingDigitsPow(n, k)<<endl;
}
