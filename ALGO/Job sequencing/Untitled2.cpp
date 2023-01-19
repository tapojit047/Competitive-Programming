#include<bits/stdc++.h>
using namespace std;
struct X
{
    int d, p, idx;
};
X ara[105];
bool func(X a, X b)
{
    return a.p > b.p;
}
bool slot[105];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d%d", &ara[i].d, &ara[i].p);
        ara[i].idx = i;
    }

    sort(ara, ara+n, func);
    vector <int> ans;

    for(int i = 0; i < n; i++){
        int k = ara[i].d;
        while(k >= 1){
            if(!slot[k]){
                slot[k] = 1;
                ans.push_back(ara[i].idx);
                break;
            }
            k--;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}
