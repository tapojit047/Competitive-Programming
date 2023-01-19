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

int main()
{
//    optimize
    int t;
    cin>>t;
    while(t--){
        double r1, r2, h, p;
        cin>>r1>>r2>>h>>p;

        double r3 = r2 + (((r1-r2)/h)*p);

        double ans = PI*p*(r3*r3+r2*r2+(r2*r3))/3;

        cout<<"Case "<<Case++<<": ";
        printf("%.10f\n", ans);
    }
}
