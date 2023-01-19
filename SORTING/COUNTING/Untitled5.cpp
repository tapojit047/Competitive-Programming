#include<bits/stdc++.h>
using namespace std;
int counti[10005];
int ans[105];
int main()
{
    int n, ara[105];
    int maxi = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        counti[ara[i]]++;

        maxi = max(ara[i], maxi);
    }

    for(int i = 1; i <= maxi; i++){
        counti[i] = counti[i-1]+counti[i];
    }

    for(int i = 0; i < n; i++){
        ans[counti[ara[i]]] = ara[i];
        counti[ara[i]]--;
    }

    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
