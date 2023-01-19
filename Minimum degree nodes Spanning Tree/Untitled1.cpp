#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define piii pair <int, pair <int, int> >
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

int n, m;
vector <pii> e;
vector <pii> edges;
int deg[MX];
int Rank[MX];
int deginmst[MX];
int ROOT[MX];
vector <pii> ans;

void initialize()
{
    for(int i = 1; i <= n; i++) ROOT[i] = i, Rank[i] = 1;
}

int root(int u)
{
    while(ROOT[u] != u){
        ROOT[u] = ROOT[ROOT[u]];
        u = ROOT[u];
    }
    return u;
}

void uni(int u, int v)
{
    int r1 = root(u);
    int r2 = root(v);

    if(Rank[r1] > Rank[r2]){
        ROOT[r2] = ROOT[r1];
        Rank[r1] += Rank[r1];
    }
    else{
        ROOT[r1] = ROOT[r2];
        Rank[r2] += Rank[r1];
    }
}

void kruskal()
{
    initialize();
    for(auto x: edges){

        if(x.first == x.second) continue;
        if(deginmst[x.first]+1 > n/2 || deginmst[x.second]+1 > n/2) continue;

        if(root(x.first) != root(x.second)){
            ans.push_back(x);
            deginmst[x.first]++;
            deginmst[x.second]++;
            uni(x.first, x.second);
        }
    }
}

bool func(pii a, pii b)
{
    if(deg[a.first] != deg[b.first]){
        return deg[a.first] < deg[b.first];
    }
    return deg[a.second] < deg[b.second];
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;

        for(int i = 0; i < m; i++){
            int u, v;
            cin>>u>>v;
            if(u == v) continue;
            edges.push_back({u, v});
            deg[u]++;
            deg[v]++;
        }

        for(int i = 0; i < edges.size(); i++){
            if(deg[edges[i].first] < deg[edges[i].second]){
                swap(edges[i].first, edges[i].second);
            }
        }

        sort(edges.begin(), edges.end(), func);

        kruskal();

        bool no = 0;
        if(ans.size() != n-1) no = 1;

        if(no) cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            for(auto x: ans) cout<<x.first<<' '<<x.second<<endl;
        }

        for(int i = 1; i <= n; i++){
            deg[i] = 0;
            deginmst[i] = 0;
        }
        edges.clear();
        e.clear();
        ans.clear();
    }
}

