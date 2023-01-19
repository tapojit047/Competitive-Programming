#include<bits/stdc++.h>
using namespace std;
//#define RESET(a) memset(a, 1, sizeof(a))
int ara[100005];
int lis[100005];
int n;

int LIS()
{
    for(int i = 0; i < n; i++){
        lis[i] = 1;
    }
    int maxV = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ara[i] > ara[j]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
        if(lis[i] > maxV){
            maxV = lis[i];
        }
    }
    return maxV;

}
int main()
{
    for(int t = 1; ; t++){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d", &ara[i]);
        }
        cout<<LIS()<<endl;
    }
}
