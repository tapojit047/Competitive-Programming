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

int dp[MX][(1<<10)+2];
int n;

int func(int pos, int mask)
{
    int &res = dp[pos][mask];
    if(res != -1) return res;
    if(pos == n){
        if(mask == (1<<10)-1) return 1;
        return 0;
    }

    int l = 0;
    if(!pos) l++;
    res = 0;
    for(int i = l; i < 10; i++){
        res += func(pos+1, mask | (1<<i));
    }
    return res;
}

///Count N length numbers without leading zeros that used all digits(0-9) at least once

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        RESET(dp, -1);

        cout<<func(0, 0)<<endl;
    }
}
