#include<bits/stdc++.h>
using namespace std;
double sum[1000001];

int main()
{
    int T, n, base;
    scanf("%d", &T);
    //sum[1] = log(1);
    for(int i = 2; i <= 1000000; i++){
        sum[i] = sum[i-1] + log(i);
    }
    for(int t = 1; t <= T; t++){
        scanf("%d%d", &n, &base);
        if(n == 0){
            printf("Case %d: %.0lf\n", t, ceil((sum[n]/log(base))) + 1);
            continue;
        }
        printf("Case %d: %.0lf\n", t, ceil((sum[n]/log(base))));
    }
}
