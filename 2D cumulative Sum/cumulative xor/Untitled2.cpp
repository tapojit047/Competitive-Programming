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

const ll MX = 1e3 + 105;

int ara[MX][MX];
int dp[MX][MX];

int func(int si, int sj, int ei, int ej)
{
    int ans = dp[ei][ej]-dp[ei][sj-1]-dp[si-1][ej]+dp[si-1][sj-1];

//    error(si, sj, ei, ej, ans);
    return ans;
}

void solve()
{
    int n, m, q;
    cin>>n>>m>>q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>ara[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j]^dp[i][j-1]^dp[i-1][j-1]^ara[i][j];
        }
    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j<= m; j++) cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }
    while(q--){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        x1++, y1++, x2++, y2++;

        int ans = dp[x2][y2]^dp[x1-1][y2]^dp[x2][y1-1]^dp[x1-1][y1-1];
        cout<<ans<<endl;
    }
}

int main()
{
    optimize
    int t = 1;
//    cin>>t;
    while(t--){
        solve();
    }
}
