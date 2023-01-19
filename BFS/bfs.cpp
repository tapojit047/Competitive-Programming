#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    ll a;
    ll d;
};

bool visited[30001];
vector <Node> adj[30001];
ll dis[30001];
void bfs(ll startingNode)
{
    memset(visited, 0, sizeof(visited));
    memset(dis, -1, sizeof(dis));
    queue <ll> q;
    q.push(startingNode);
    dis[startingNode] = 0;
    ll x;
    while(!q.empty()){
        x = q.front();
       // cout<<x<<' '<<endl;
        q.pop();
        visited[x] = 1;
        for(int i = 0; i < adj[x].size(); i++){
            if(!visited[adj[x][i].a]){
               // if((dis[x] + adj[x][i].d) < dis[adj[x][i].a]){
                    dis[adj[x][i].a] = dis[x] + adj[x][i].d;
                    q.push(adj[x][i].a);
                //}
            }
        }
    }
}
int main()
{
    ll T, n, m, u, v, w;
    Node x;
    //cout<<INF<<endl;
    scanf("%lld", &T);
    for(ll t = 1; t <= T; t++){
        scanf("%lld", &n);
        for(int i = 0; i < n-1; i++){
            scanf("%lld%lld%lld", &u, &v, &w);
            x.a = v, x.d = w;
            adj[u].push_back(x);
            x.a = u, x.d = w;
            adj[v].push_back(x);
        }
        ll maxi = -1, x;
//        for(int i = 0; i < n; i++){
//            cout<<i<<endl;
//            for(int j = 0; j < adj[i].size(); j++){
//                cout<<adj[i][j].a<<' '<<adj[i][j].d<<endl;
//            }
//        }
        bfs(0);
        for(int i = 0; i < n; i++){
            if(dis[i] > maxi){
                maxi = dis[i];
                x = i;
            }
        }
        bfs(x);
        maxi = -1;
        for(int i = 0; i < n; i++){
            if(dis[i] > maxi){
                maxi = dis[i];
            }
        }

      //  cout<<endl;
        printf("Case %lld: %lld\n", t, maxi);
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
    }
}
