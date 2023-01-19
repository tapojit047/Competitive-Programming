#include <bits/stdc++.h>
using namespace std;
#define MX 90
#define RESET(ara, b) memset(ara, b, sizeof(ara))
typedef long long ll;

ll A, B, K;
vector <ll> digits;
ll dp[12][2][MX][MX];

ll solve(ll n, bool f1, ll num, ll sum)
{
    if(n == digits.size()){
        if(num % K == 0 && sum % K == 0){
            return 1;
        }
        return 0;
    }
    ll &res = dp[n][f1][num][sum];
    if(res != -1){
        return res;
    }
    //cout<<n<<' '<<f1<<' '<<num<<' '<<sum<<endl;
    ll ans = 0;
    ll k = f1 ? 9 : digits[n];

    for(int i = 0; i <= k; i++){
        ans += solve(n+1, i < digits[n] ? 1 : f1, (num*10 + i)%K, (sum+i)%K);
    }

    return res = ans;
}

int main()
{
    ll T;
    scanf("%lld", &T);

    for(int t = 1; t <= T; t++){

        scanf("%lld%lld%lld", &A, &B, &K);
        if(K > 83){
                printf("Case %d: 0\n", t);
                continue;
        }
        A--;
        digits.clear();
        RESET(dp, -1);

        while(A){
            digits.push_back(A%10);
            A /= 10;
        }
        reverse(digits.begin(), digits.end());
        ll ans1 = solve(0, 0, 0, 0);

        digits.clear();
        while(B){
            digits.push_back(B%10);
            B /= 10;
        }

        reverse(digits.begin(), digits.end());
        RESET(dp, -1);
        ll ans2 = solve(0, 0, 0, 0);

        printf("Case %d: %lld\n", t, ans2-ans1);
    }
    return 0;
}
