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
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)

#define        MX        200005

vector <int> adj[MX];
vector <pii> edges;
vector <int> order;
int pos[MX];
vector <bool> visited;

void dfs(int n)
{
    visited[n] = 1;
    for(auto x: adj[n]){
        if(!visited[x]){
            dfs(x);
        }
    }
    order.push_back(n);
}

int main()
{
    optimize
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    visited = vector <bool> (n+1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i);
    }

    reverse(order.begin(), order.end());
    for(int i = 0; i < n; i++){
        pos[order[i]] = i;
    }

    bool cycle = 0;
    for(int i = 1; i <= n; i++){
        for(auto x: adj[i]){
            if(pos[i] > pos[x]){
                cycle = 1;
                break;
            }
        }
    }
    if(cycle) YES
    else NO
}
