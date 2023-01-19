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

const ll MX = 1e3 + 105;

int dp[MX][MX];
pii Next[MX][MX];
string str;

int func(int b, int e)
{
    int &res = dp[b][e];

    if(res != -1) return res;
    if(b == e) return 1;
    if(b > e) return 0;

    res = 0;
    if(str[b] == str[e]){
        res = func(b+1, e-1)+2;
        Next[b][e] = {b+1, e-1};
    }
    else{
        int val1 = func(b+1, e);
        int val2 = func(b, e-1);

        if(val1 > val2){
            Next[b][e] = {b+1, e};
        }
        else{
            Next[b][e] = {b, e-1};
        }
        res = max(val1, val2);
    }
    return res;
}

string ans, rev;

void track(int b, int e)
{
    if(b == e){
        ans += str[b];
        return;
    }
    if(b > e) return;

    int nextb = Next[b][e].first, nexte = Next[b][e].second;
    if(nextb == b+1 && nexte == e-1){
        ans += str[b];
        rev += str[b];
    }
    track(nextb, nexte);
}

int main()
{
    optimize
    cin>>str;
    RESET(dp, -1);

    cout<<func(0, str.size()-1)<<endl;
    track(0, str.size()-1);

    reverse(rev.begin(), rev.end());
    ans = ans + rev;
    cout<<ans<<endl;
}
