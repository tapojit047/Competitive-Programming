#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

#define        MX        200005

int ara[MX];

int main()
{
    optimize
    int n, sum;
    cin>>n>>sum;

    vector <int> pre(n+1);
    for(int i = 0; i < n; i++){
        cin>>ara[i];
        pre[i+1] = pre[i] + ara[i];
    }

    map <ll, ll> m;
    ll ans = 0;

    for(int i = 1; i <= n; i++) cout<<pre[i]<<' ';
    cout<<endl;

    for(int i = 1; i <= n; i++){
        m[pre[i-1]+sum]++;
        ans += m[pre[i]];
    }
    cout<<ans<<endl;
}
