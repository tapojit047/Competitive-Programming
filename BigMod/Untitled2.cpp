#include<bits/stdc++.h>
using namespace std;
ll bigmod(ll a, ll b, ll M)
{
    if(b == 0){
        return 1 % M;
    }
    ll x = bigmod(a, b/2);
    x = (x*x) % M;
    if(b % 2 == 1){
        x = (x*a) % M;
    }
    return x;
}
int main()
{
    int n = 2147483647;
    cout<<n<<endl;
}
