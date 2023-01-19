#include<bits/stdc++.h>
using namespace std;
struct X
{
    double w, p;
    double val;
};
X ara[105];
bool func(X a, X b)
{
    return a.val > b.val;
}
int main()
{
    int n, we;
    scanf("%d%d", &n, &we);

    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &ara[i].w, &ara[i].p);
        ara[i].val = ara[i].p/ara[i].w;
    }

    sort(ara, ara+n, func);

    double tp = 0, tw = 0;
    for(int i = 0; i < n; i++){
       // cout<<tp<<endl;
        if(tw + ara[i].w <= we){
            tw += ara[i].w;
            tp += ara[i].p;
        }
        else{
            double x = (we-tw);
            x /= ara[i].w;
            tp += ara[i].p*x;
        }
    }
    cout<<tp<<endl;
}
