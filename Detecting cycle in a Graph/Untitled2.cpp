#include<bits/stdc++.h>
using namespace std;

vector <int> adj[101];
bool visited[101];
int starting[101];
int ending[101];
int Time = 1;
bool cycle = 0;

stack <int> ans;
void dfs(int n)
{
    starting[n] = Time;
    Time++;
    visited[n] = true;
    for(int i = 0; i < adj[n].size(); i++){
        if(!visited[adj[n][i]]){
            dfs(adj[n][i]);
        }
	else if(ending[adj[n][i] == -1){
		cycle = 1;
		return;
	}
    }
    ending[n] = Time;
    ans.push(n);
    Time++;
}

int main()
{
    int n, u, v, nodes;
    scanf("%d%d", &n, &nodes);

    for(int i = 0; i < n; i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){

        if(!visited[i]){
            dfs(i);
        }
    }

    for(int i = 1; i <= nodes; i++){
        printf("%c", 'A'+i-1);
        cout<<' '<<starting[i]<<' '<<ending[i]<<endl;
    }
    cout<<endl<<endl;

    while(!ans.empty()){
        printf("%c\n", ans.top()+'A'-1);
        ans.pop();
    }
}
