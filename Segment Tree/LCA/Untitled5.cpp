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

const ll MX = 3e4 + 105;

int height[MX], first[MX], tree[4*MX];
vector <int> adj[MX], euler;
int n, m;

void build(int node, int b, int e)
{
    if(b == e){
        tree[node] = euler[b];
        return;
    }

    int left = (node<<1);
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);

    int l = tree[left], r = tree[right];
//    tree[node] = min(tree[left], tree[right]);
    tree[node] = (height[l] < height[r]) ? l : r;
}

int query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return -1;
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;

    int ans = (height[p1] < height[p2]) ? p1 : p2;
    return ans;
}

void dfs(int u, int par)
{
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v: adj[u]){
        if(v == par) continue;
        height[v] = height[u]+1;
        dfs(v, u);
        euler.push_back(u);
    }
}

void LCA_PRE()
{
    euler.clear();
    dfs(0, 0);
    m = euler.size();
    build(1, 0, m-1);
}

int LCA(int a, int b)
{
    a = first[a];
    b = first[b];
    if(a > b) swap(a, b);

    return query(1, 0, m-1, a, b);
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        LCA_PRE();
        int m;
        cin>>m;
        while(m--){
            int u, v;
            cin>>u>>v;
            cout<<LCA(u, v)<<endl;
        }
    }
}
