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
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)

#define        MX        1005

ll ncr[MX][MX];

void pascal(ll n)
{
    ////using pascal triange O(n^2)
    ncr[0][0] = 1;
    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= i; j++){
            if(j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}

int main()
{
    optimize
    pascal(1000);
    int q, n, r;;
    cin>>q;

    while(q--){
        cin>>n>>r;
        cout<<ncr[n][r]<<endl;
    }
}
