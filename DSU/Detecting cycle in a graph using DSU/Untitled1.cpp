#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 5;

int parent[MX];
int Rank[MX];
vector <int> adj[MX];

int Find(int i)
{
    if(parent[i] != i){
        return parent[i] = Find(parent[i]);
    }
    return i;
}
bool Union(int u, int v)
{
    int uroot = Find(u);
    int vroot = Find(v);
    error(u, v, uroot, vroot);
    if(uroot == vroot) return 1;
    if(Rank[uroot] > Rank[vroot]) parent[vroot] = uroot;
    else if(Rank[uroot] < Rank[vroot]) parent[uroot] = vroot;
    else{
        parent[vroot] = uroot;
        Rank[uroot]++;
    }
    return 0;
}
int main()
{
    optimize
    int n, m;
    cin>>n>>m;

    vector <pii> edges;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back(pii(u, v));
    }
    ///Detecting cycle using DSU
    for(int i = 1; i <= n; i++) parent[i] = i;

    bool yes = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        if(Union(u, v)){
            yes = 1;
            break;
        }
    }

    if(yes) YES;
    else NO;
}
