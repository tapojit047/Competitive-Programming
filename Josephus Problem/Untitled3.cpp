#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll josephus(ll n, ll k)
{
    if(n == 1){
        return 1;
    }
    ll x = (josephus(n-1, k) + k) % n;
    if(x == 0){
        x = n;
    }
    return x;
}
int main()
{
    ll T, n, k;
    cin>>T;

    for(int t = 1; t <= T; t++){
        cin>>n>>k;
        printf("Case %d: ", t);
        cout<<josephus(n, k)<<endl;
    }
}
