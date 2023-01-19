#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;
const ll K = 20;

vector <int> adj[MX];
int up[MX][K+1];
int timer, tin[MX], tout[MX];

void dfs(int u, int par)
{
    tin[u] = ++timer;
    up[u][0] = par;
    for(int i = 1; i <= K; i++) up[u][i] = up[up[u][i-1]][i-1];

    for(auto v: adj[u]){
        if(v == par) continue;

        dfs(v, u);
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = K; i >= 0; i--){
        if(up[u][i] && !is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main()
{
    optimize
    int n;
    cin>>n;
    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    int m;
    cin>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
}
