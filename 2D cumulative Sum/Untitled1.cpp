#include<bits/stdc++.h>
using namespace std;
int sum[105], N, M;
void RESET()
{
    for(int i = 1; i <= N; i++){
        sum[i] = 0;
    }
}
int main()
{
    int ara[105][105];
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &ara[i][j]);
        }
    }

    int msum = ara[1][1], csum = 0, l = 1, r = 1, u = 1, d = 1;

    for(int i = 1; i <= M; i++){
        int right = i;
        while(right <= M){
            int s = 0, ms = ara[right][1], up = 1, down = 1, cup = 1, cdown = 1;
            for(int j = 1; j <= N; j++){
                //cout<<s<<endl;
                sum[j] += ara[j][right];

                ///kadane
                if(sum[j] > s+sum[j]){
                    s = sum[j];
                    cup = j, cdown = j;
                }
                else{
                    s += sum[j];
                    cdown = j;
                }
                if(s > ms){
                    ms = s;
                    up = cup;
                    down = cdown;
                }
            }

            if(ms > msum){
                msum = ms;
                l = i, r = right, u = up, d = down;
            }
            right++;
        }
        RESET();
    }
    cout<<msum<<endl;
    cout<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
}
