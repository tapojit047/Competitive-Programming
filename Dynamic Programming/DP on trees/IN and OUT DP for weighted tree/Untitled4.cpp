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

#define        MX        200005

vector <pii> adj[MX];
int in[MX];
int out[MX];

void dfs1(int u, int par)
{
    for(auto v: adj[u]){
        if(v.first == par) continue;
        dfs1(v.first, u);
        in[u] = max(in[u], in[v.first]+v.second);
    }
}

void dfs2(int u, int par)
{
    int mx1 = -1, mx2 = -1;

    for(auto v: adj[u]){
        if(v.first == par) continue;

        if(in[v.first]+v.second >= mx1) mx2 = mx1, mx1 = in[v.first]+v.second;
        else if(in[v.first]+v.second >= mx2) mx2 = in[v.first]+v.second;
    }

//    error(u, mx1, mx2);
    for(auto v: adj[u]){
        if(v.first == par) continue;

        int use = mx1;
        if(in[v.first]+v.second == mx1) use = mx2;

        out[v.first] = v.second+max(out[u], use);
        dfs2(v.first, u);
    }

}


int main()
{
    optimize
    int T;
    cin>>T;
    for(int tt = 1; tt <= T; tt++){
        int n;
        cin>>n;

        for(int i = 0; i < n-1; i++){
            int u, v, w;
            cin>>u>>v>>w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        ///Here in[v] is the max height in the subtree of v
        ///Here out[v] is the max height out of the subtree of v

        dfs1(0, -1);
        dfs2(0, -1);


        cout<<"Case "<<tt<<":"<<endl;
        for(int i = 0; i < n; i++){
//            error(i, in[i], out[i]);
            cout<<max(in[i], out[i])<<endl;
        }

        for(int i = 0; i < n; i++){
            in[i] = 0, out[i] = 0;
            adj[i].clear();
        }
    }

}
