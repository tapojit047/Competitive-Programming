#include<bits/stdc++.h>
using namespace std;
int ara[105][105], sum[105], N;
int circularkadane()
{
    int a, b, ts = 0;
    int p = 0;
    while(p < 2){
        int ms, cs = 0;
        for(int i = 1; i <= N; i++){

            if(cs+sum[i] < sum[i]){
                cs = sum[i];
            }
            else{
                cs += sum[i];
            }
            if(cs > ms || i == 1){
                ms = cs;
            }

            if(p == 0){
                ts += sum[i];
            }

            sum[i] *= (-1);
        }
        if(p == 0){
            a = ms;
            p++;
        }
        else if(p == 1){
            p++;
            b = ts+ms;
        }
        //cout<<p<<' '<<ms<<endl;

        /*for(int i = 1; i <= N; i++){
            cout<<sum[i]<<' ';
        }
        cout<<endl; */
    }
    if(b == 0){
        for(int i = 1; i <= N; i++){
            if(sum[i] == 0){
                return b;
            }
        }
        return a;
    }
    //cout<<a<<' '<<b<<' '<<ts<<endl;
    return max(a, b);

}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &sum[i]);
    }
}
