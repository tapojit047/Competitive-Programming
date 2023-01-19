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

string str;
ll dp[15][2][2];
ll dp1[15][2][2];
int Case = 1;

void func(ll pos, bool isSmall, bool iszeroleading)
{
    ll &res = dp[pos][isSmall][iszeroleading];
    ll &res1 = dp1[pos][isSmall][iszeroleading];
    if(res != -1) return;
    if(pos == str.size()){
        res = 0;
        res1 = 1;
        return;
    }

    int till = str[pos]-'0';
    if(isSmall) till = 9;

    res = 0;
    res1 = 0;
    for(int i = 0; i <= till; i++){
        bool newisSmall = ((i < (str[pos]-'0')) | isSmall);
        bool newiszeroleading = (!i & iszeroleading);

        func(pos+1, newisSmall, newiszeroleading);
        res += dp[pos+1][newisSmall][newiszeroleading];
        res1 += dp1[pos+1][newisSmall][newiszeroleading];
        if(i == 0 && !iszeroleading){
            res += dp1[pos+1][newisSmall][newiszeroleading];
        }
    }
}

///write all the numbers from a to b inclusive how many zeros will be written down?

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;

        str = b;
        RESET(dp, -1);
        RESET(dp1, -1);
        func(0, 0, 1);
        ll ansr = dp[0][0][1];

        str = a;
        RESET(dp, -1);
        RESET(dp1, -1);
        func(0, 0, 1);
        ll ansl = dp[0][0][1];

        ll ans = ansr-ansl;
        for(auto x: a) if(x == '0') ans++;

        cout<<"Case "<<Case++<<": ";
        cout<<ans<<endl;
    }
}
