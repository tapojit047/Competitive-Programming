#include<bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
int IP[100005];

int visited[100005];
int discovery[100005];
int parents[100005];
int lower[100005];

int times = 0;

void dfs(int n)
{
    times++;
    discovery[n] = times;
    lower[n] =  times;
    visited[n] = 1;
    int child = 0;

    for(int i = 0; i < adj[n].size(); i++){
        if(!visited[adj[n][i]]){

            child++;
            parents[adj[n][i]] = n;
            dfs(adj[n][i]);

            lower[n] = min(lower[n], lower[adj[n][i]]);

            if(parents[n] != -1 && lower[adj[n][i]] >= discovery[n]){
                IP[n]++;
            }
        }

        else if(parents[n] != adj[n][i]){
            lower[n] = min(lower[n], discovery[adj[n][i]]);
        }
    }

    ///root
    if(parents[n] == -1 && child > 1){
        IP[n]++;
    }
}
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    for(int i = 0; i < M; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parents, -1, sizeof(parents));
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(int i = 1; i <= N; i++){
        cout<<IP[i]<<' ';
    }
    cout<<endl;
}
/*
6 5
5 2
5 4
5 6
2 1
2 3
*/
