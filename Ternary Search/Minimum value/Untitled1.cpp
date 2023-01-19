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
#define pii pair <double, double>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define s first
#define d second

//inline bool Equal(double x, double y) { return fabs(x-y)<eps; }
//inline bool Greater(double x, double y){ return x-eps>y; }
//inline bool Lesser(double x, double y){ return x+eps<y; }

const ll MX = 2e5 + 105;

pii ara[MX];
ll n, k;

double func(double t)
{
    double minval = 1e18, maxval = -1e18;
    for(int i = 0; i < n; i++){
        double cur = ara[i].d+ara[i].s*t;
        minval = min(minval, cur);
        maxval = max(maxval, cur);
    }
    return (maxval-minval);
}

double ts()
{
    double l = 0, r = k;
    double eps = 1e-9;
    while(r-l > eps){
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;

        double fm1 = func(m1);
        double fm2 = func(m2);

        if(fm1 < fm2) r = m2;
        else l = m1;
    }
    return func(l);
}

int main()
{
//    optimize
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>ara[i].s>>ara[i].d;
    }
    double ans = ts();
    printf("%.6f\n", ans);
//    cout<<setprecision(6)<<ans<<endl;

}
