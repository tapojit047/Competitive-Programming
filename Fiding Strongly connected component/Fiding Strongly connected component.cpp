#include<bits/stdc++.h>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))

vector <int> adj[1005];
vector <int> adj1[1005];
vector <int> compo[1005];

bool visited[1005];

stack <int> s;

bool b;
int c;

void dfs(int n)
{
    visited[n] = 1;

    if(b){
        compo[c].push_back(n);
    }

    if(!b){

        for(int i = 0; i < adj[n].size(); i++){
            if(!visited[adj[n][i]]){
                dfs(adj[n][i]);
            }
        }
    }
    else{

        for(int i = 0; i < adj1[n].size(); i++){
            if(!visited[adj1[n][i]]){
                dfs(adj1[n][i]);
            }
        }
    }

    if(!b){

        s.push(n);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i++){

        int u, v;

        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj1[v].push_back(u);
    }

    b = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }


    RESET(visited, 0);

    b = 1, c = 0;

    while(!s.empty()){

        int x = s.top();
        cout<<x<<' ';
        s.pop();

        if(!visited[x]){
            dfs(x);
            c++;
        }
    }
    cout<<endl;

    for(int i = 0; i < c; i++){
        for(int j = 0; j < compo[i].size(); j++){
            cout<<compo[i][j]<<' ';
        }
        cout<<endl;
    }
}
