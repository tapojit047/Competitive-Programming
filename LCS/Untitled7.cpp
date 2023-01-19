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

const ll MX = 5e3 + 105;

int dp[MX][MX];
string s1, s2;
int n, m;

int lcs(int i, int j)
{
    if(i == n || j == m){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        dp[i][j] = 1+lcs(i+1, j+1);
    }
    else{
        dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));
    }
    return dp[i][j];
}

int main()
{
    optimize

    cin>>s1>>s2;
    n = s1.size(), m = s2.size();
    RESET(dp, -1);
    cout<<lcs(0, 0)<<endl;
}
