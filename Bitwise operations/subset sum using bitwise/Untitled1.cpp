#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define child adj[n][i]

#define        MX        200005
int ara[MX];
int main()
{
    int N, S;
    cin>>N>>S;

    for(int i = 0; i < N; i++){
        cin>>ara[i];
    }

    bool yes = 0;
    for(int mask = 0; mask < (1<<N); mask++){
        int subsum = 0;
        for(int i = 0; i < N; i++){
            if(mask & (1<<i)){
                subsum += ara[i];
            }
        }
        if(subsum == S){
            YES;
            yes = 1;
            break;
        }
    }
    if(!yes){
        NO;
    }
}
