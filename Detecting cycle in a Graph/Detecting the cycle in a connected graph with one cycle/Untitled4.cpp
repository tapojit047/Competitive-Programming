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
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

vector <int> adj[MX];
bool visited[MX];
set <int> cycle;
bool done;
int parent[MX];
int n;

void detect_cycle(int u, int p)
{
    visited[u] = 1;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(done) return;
        if(!visited[v]){
            parent[v] = u;
            detect_cycle(v, u);
        }
        else{
            while(u != -1){
                cycle.insert(u);
                if(u == v){
                    done = 1;
                    return;
                }
                u = parent[u];
            }
        }
    }
}

// Resource problem: https://codeforces.com/contest/1454/problem/E

int main()
{
    optimize
    cin>>n;
    for(int i = 0; i < n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    detect_cycle(1, -1);

    for(auto x: cycle) cout<<x<<' ';
    cout<<endl;

}
