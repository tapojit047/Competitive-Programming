#include<bits/stdc++.h>
using namespace std;
#define RESET(a, b) memset(a, b, sizeof(a))

int price[1005];
int weg[1005];
int DP[1005][50];
int cap, N;

int dp(int i, int w)
{
    if(w >= cap){
        return 0;
    }
    if(i == N){
        return 0;
    }

    if(DP[i][w] != -1){
        return DP[i][w];
    }

    int p1 = 0, p2 = 0;

    if(w+weg[i] <= cap){
        p1 = price[i] + dp(i+1, w+weg[i]);
    }

    p2 = dp(i+1, w);
    //cout<<i<<' '<<p1<<' '<<p2<<endl;
    DP[i][w] = max(p1, p2);
    return DP[i][w];
}
int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++){
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            scanf("%d%d", &price[i], &weg[i]);
        }
        int M;
        scanf("%d", &M);

        int ans = 0;

        for(int i = 0; i < M; i++){
            scanf("%d", &cap);
            RESET(DP, -1);
            //cout<<DP[0]<<endl;
            ans += dp(0, 0);
            //cout<<ans<<endl;
        }
        printf("%d\n", ans);
    }
}
