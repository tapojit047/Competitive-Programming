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
#define pii pair <ll, ll>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 1e4 + 105;

///Given N, calculate how many permutations of length N(ara[1], ara[2], ara[3],....,ara[n]) exist where for each i (1<i<N),
///either of the following conditions is satisfied,

///1. ara[i] > ara[i+1] and ara[i] > ara[i-1]
///2. ara[i] < ara[i+1] and ara[i] < ara[i-1]

///(1<=N<=10000)

ll n;
ll dp[2][2][MX];
ll csum[2][2][MX];
/// position type prev

int main()
{
    optimize
    cin>>n;

    for(ll i = 1; i <= n; i++){
        dp[(n+1)&1][0][i] = dp[(n+1)&1][1][i] = 1;
        csum[(n+1)&1][0][i] = csum[(n+1)&1][0][i-1]+dp[(n+1)&1][0][i];
        csum[(n+1)&1][1][i] = csum[(n+1)&1][1][i-1]+dp[(n+1)&1][1][i];
    }

    for(ll pos = n; pos >= 2; pos--){
        ll curMax = n-pos+1;

        for(ll type = 0; type <= 1; type++){

            for(ll prev = 1; prev <= n-pos+2; prev++){

                if(type == 0){
//                    for(ll k = 1; k < prev; k++)
//                        dp[pos][type][prev] += dp[(pos+1)&1][1][k];
                    dp[pos&1][type][prev] = csum[(pos+1)&1][1][prev-1]-csum[(pos+1)&1][1][0];
                }
                else{
//                    for(ll k = prev; k <= n-(pos+1)&1; k++)
//                        dp[pos][type][prev] += dp[(pos+1)&1][0][k];
                    dp[pos&1][type][prev] = csum[(pos+1)&1][0][curMax]-csum[(pos+1)&1][0][prev-1];
                }
                csum[pos&1][type][prev] = csum[pos&1][type][prev-1]+dp[pos&1][type][prev];
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += dp[0][0][i];
        ans += dp[0][1][i];
    }
    cout<<ans<<endl;
}
