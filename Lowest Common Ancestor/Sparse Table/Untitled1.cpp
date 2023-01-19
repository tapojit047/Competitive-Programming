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
const ll K = 26;

vector <int> adj[MX];
int height[MX];
int first[MX];
vector <int> euler;
int st[MX][K];
int cnt[MX];
int Case = 1;

void dfs(int u, int par)
{
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v: adj[u]){
        if(v == par) continue;

        height[v] = height[u] + 1;
        dfs(v, u);
        euler.push_back(u);
    }
}

void sparse()
{
    for(int i = 0; i < euler.size(); i++) st[i][0] = euler[i];

    for(int j = 1; j < K; j++){
        for(int i = 0; i + (1<<j) <= euler.size(); i++){
            int a = st[i][j-1];
            int b = st[i + (1<<(j-1))][j-1];

            if(height[a] < height[b]) st[i][j] = a;
            else st[i][j] = b;
        }
    }
}

int rmq(int L, int R)
{
    int j = log2(R-L+1);
    int a = st[L][j];
    int b = st[R - (1<<j) + 1][j];

    if(height[a] < height[b]) return a;
    else return b;
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
        dfs(1, 0);
        /// ROOT --> 1
        sparse();

        int m;
        cin>>m;
        cout<<"Case "<<Case++<<":"<<endl;
        while(m--){
            int u, v;
            cin>>u>>v;
            if(first[u] > first[v]) swap(u, v);

            cout<<rmq(first[u], first[v])<<endl;
        }


//        for(int i = 0; i < euler.size(); i++){
//            for(int j = 0; j < K; j++){
//                st[i][j] = 0;
//            }
//        }
//        euler.clear();
//        for(int i = 1; i <= n; i++){
//            first[i] = 0;
//            height[i] = 0;
//            cnt[i] = 0;
//            adj[i].clear();
//        }
}
