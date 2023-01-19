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
///Here a = long parallel side
    /// b = short parallel side
    /// c = non parallel side
    /// d = non parallel side

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        double a, b, c, d;
        scanf("%lf%lf%lf%lf", &a, &c, &b, &d);

        if(a < b) swap(a, b);

        double s = (a+b+c+d)/2;

        double area = (a+b)*sqrt((s-a)*(s-b)*(s-a-c)*(s-a-d))/(a-b);
        printf("Case %d: %.10lf\n", Case++, area);
    }
}
