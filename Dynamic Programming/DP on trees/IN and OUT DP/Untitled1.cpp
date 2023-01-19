#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

#define        MX        200005

vector <int> adj[MX];
int in[MX];
int out[MX];
int dp[MX];

void dfs1(int u, int par)
{
    for(int v: adj[u]){
        if(v == par) continue;
        dfs1(v, u);
        in[u] = max(in[u], in[v]+1);
    }
}

void dfs2(int u, int par)
{
    int mx1 = -1, mx2 = -1;

    for(int v: adj[u]){
        if(v == par) continue;

        if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if(in[v] >= mx2) mx2 = in[v];
    }

    for(int v: adj[u]){
        if(v == par) continue;

        int use = mx1;
        if(in[v] == mx1) use = mx2;

        out[v] = 1+max(out[u], use+1);
        dfs2(v, u);
    }

}


int main()
{
    optimize
    int n;
    cin>>n;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ///Here in[v] is the max height in the subtree of v
    ///Here out[v] is the max height out of the subtree of v

    dfs1(1, 0);
    dfs2(1, 0);

    for(int i = 1; i <= n; i++){
        dp[i] = max(in[i], out[i]);
    }

    for(int i = 1; i <= n; i++){
        cout<<in[i]<<' ';
    }
    cout<<endl;
    for(int i = 1; i <= n; i++){
        cout<<out[i]<<' ';
    }
    cout<<endl;

    for(int i = 1; i <= n; i++){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
}
