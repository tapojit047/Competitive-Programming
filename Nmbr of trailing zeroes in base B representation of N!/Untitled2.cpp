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

const ll MX = 2e5 + 5;
const ll inf = 1e18+10;

vector <pii> pdiv;
void PrimeFactors(ll num)
{
    if(num%2 == 0){
        ll c = 0;
        while(num%2 == 0){
            num /= 2;
            c++;
        }
        pdiv.push_back({2, c});
    }
    //till sqrt(num)
    for(ll i = 3; i*i <= num; i+=2){
        if(num%i == 0){
            ll c = 0;
            while(num%i == 0){
                num /= i;
                c++;
            }
            pdiv.push_back({i, c});
        }
    }
    if(num > 2){
        pdiv.push_back({num, 1});
    }
}
ll FindPower(ll n, ll p)
{
    ll r = p;
    ll ans = 0;
    ll c = log(n)/log(r);
    while(r <= n && c){
//        cout<<n<<' '<<r<<endl;
        ans += (n/r);
        c--;
        r *= p;
    }
    return ans;
}
ll largestpowerofP(ll n)
{
    ll ans = inf;
    for(int i = 0; i < pdiv.size(); i++){
        ll power = FindPower(n, pdiv[i].first)/pdiv[i].second;
        ans = min(ans, power);
    }
    return ans;
}

int main()
{
    optimize
    ll n, p;
    cin>>n>>p;
    PrimeFactors(p);
    cout<<largestpowerofP(n)<<endl;
}
