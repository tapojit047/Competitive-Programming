#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl; continue;
#define NO cout<<"NO"<<endl; continue;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)
#define val first
#define we second
#define        MX        200005
vector < pii > ara;
int n, wt;
bool sortbysec(pii a, pii b)
{
    return (a.second < b.second);
}
int dp[1000][1000];
void knapsack()
{
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= wt; w++){

            if(i == 0 || w == 0) dp[i][w] = 0;

            else if(ara[i].we <= w){
                dp[i][w] = max(dp[i-1][w], (ara[i].val + dp[i-1][w-ara[i].we]) );
            }

            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
}
int main()
{
    optimize
    cin>>n>>wt;

    ///first is value, second is weight
    ara.pb(pii(0, 0));
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        ara.pb(pii(a, b));
    }

    sort(ara.begin(), ara.end(), sortbysec);
    for(int i = 1; i <= n; i++){
        cout<<ara[i].val<<' '<<ara[i].we<<endl;
    }
    knapsack();

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= wt; j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[n][wt]<<endl;
}
//3 50
//60 10
//100 20
//120 30
