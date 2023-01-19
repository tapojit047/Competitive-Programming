#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define child adj[n][i]

#define        MX        200005

int main()
{
    ll x;
    cin>>x;
    for(int i = 30; i >= 0; i--){
        if(x & (1LL<<i)){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
//    while(x){
//        cout<<x<<endl;
//        cout<<x%2;
//        x>>1;
//    }
}
