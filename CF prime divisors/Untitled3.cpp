#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)
#define        MX        200005
void primediv()
{
    ll x;
    cin>>x;

    vector <int> primediv;
    for(ll i = 2 ; i * i <= x ; i++){
        if(x % i == 0){
            ll cur = 1;
            while(x % i == 0){
                x /= i;
                cur *= i;
            }
            primediv.pb(i);
        }
    }
    if(x > 1){
        primediv.pb(x);
    }
    for(int i = 0; i < primediv.size(); i++){
        cout<<primediv[i]<<' ';
    }
    cout<<endl;
}
int main()
{
    primediv();
}
