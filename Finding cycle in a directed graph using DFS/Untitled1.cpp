#include<bits/stdc++.h>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))

vector <int> adj[1000005];
bool visited[1000005];

bool c = 0;
stack <int> ans;

void dfs(int n, map <int, int> cycle)
{
    cycle[n] = 1;
    visited[n] = 1;
    //cout<<n<<endl;
    for(int i = 0; i < adj[n].size(); i++){
        if(cycle[adj[n][i]]){
            //cout<<n<<' '<<adj[n][i]<<endl;
            c = 0;
            return;
        }
        if(!visited[adj[n][i]] == 1){
            dfs(adj[n][i], cycle);
        }
    }
    ans.push(n);
}
int main()
{
    int N, M;
    while(1){
        scanf("%d%d", &N, &M);
        if(!N && !M){
            break;
        }

        for(int i = 0; i < M; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
        }

        c = 1;
        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                map <int, int> cycle;
                //RESET(cycle, 0);
                dfs(i, cycle);

            }
        }
       // cout<<c<<endl;
        //cout<<ans.size()<<endl;

        if(!c){
            printf("IMPOSSIBLE\n");
        }
        else{
            while(!ans.empty()){
                cout<<ans.top()<<endl;
                ans.pop();
            }
        }


        while(!ans.empty()){
            ans.pop();
        }
        for(int i = 1; i <= N; i++){
            adj[i].clear();
        }
        RESET(visited, 0);
    }
}
