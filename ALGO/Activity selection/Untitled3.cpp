#include<bits/stdc++.h>
using namespace std;
struct X
{
    int start, end, idx;
};
X ara[105];
bool func(X a, X b)
{
    return a.end < b.end;
}
bool slot[105];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d%d", &ara[i].start, &ara[i].end);
        ara[i].idx = i;
    }

    sort(ara, ara+n, func);

    vector <int> ans;
    ans.push_back(ara[0].idx);
    int seshkorechi = ara[0].end;
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<ara[i].start<<' '<<ara[i].end<<' '<<ara[i].idx<<endl;
    }
    cout<<endl;
    for(int i = 1; i < n; i++){
        if(seshkorechi <= ara[i].start){
            ans.push_back(ara[i].idx);
            seshkorechi = ara[i].end;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}
