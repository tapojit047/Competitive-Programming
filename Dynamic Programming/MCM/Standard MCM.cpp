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
#define row first
#define col second

const ll MX = 105;
const ll inf = 2e9;

int ara[MX];
pii mat[MX];
int dp[MX][MX];

int mergeCost(int b, int e, int i)
{
    int cost = mat[b].row*mat[i].col*mat[e].col;
}

int func(int b, int e)
{
    int &res = dp[b][e];
    if(res != -1) return res;
    if(b == e) return 0;

    res = inf;
    for(int i = b; i < e; i++){
        int val1 = func(b, i);
        int val2 = func(i+1, e);

        int val = val1+val2+ (mat[b].row*mat[i].col*mat[e].col);
        res = min(res, val);
    }
    return res;
}

int main()
{
    optimize
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }
    for(int i = 0; i < n-1; i++){
        mat[i].row = ara[i];
        mat[i].col = ara[i+1];
    }
    RESET(dp, -1);
    cout<<func(0, n-2)<<endl;
//    error(dp[1][2], dp[0][1]);
}
