#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ara[200005], tree[200005];
ll n, q;

void update(int idx, int val)
{
    cout<<idx<<endl;
    while(idx <= n){
        cout<<idx<<' ';
        tree[idx] += val;
        idx += (idx & -idx);
    }
    cout<<endl;
}
ll query(int idx)
{
    ll sum = 0;
    cout<<idx<<endl;
    while(idx > 0){
        cout<<idx<<' ';
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
    cout<<endl;
}
int main()
{
    cin>>n>>q;

    for(int i = 1; i <= n; i++){
        scanf("%I64d", &ara[i]);
        update(i, ara[i]);
    }

    for(int i = 1; i <= n; i++){
        cout<<tree[i]<<' ';
    }
    cout<<endl;
    for(int i = 0; i < q; i++){
        int p;
        cin>>p;
        cout<<query(p)<<endl;
    }
}
