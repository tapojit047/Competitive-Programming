#include<bits/stdc++.h>
using namespace std;
int n, m;
vector <int> ans;
bool visited[1005];
vector <int> adj[1005];
int indeg[1005];

void alltopsort()
{
    bool flag = 0;
    for(int i = 0; i < n; i++){
        if(!indeg[i]){

            indeg[i]--;

            for(int j = 0; j < adj[i].size(); j++){
                indeg[adj[i][j]]--;
            }

            ans.push_back(i);
            alltopsort();

            ///backtracking
            ans.erase(ans.end()-1);
            indeg[i]++;

            for(int j = 0; j < adj[i].size(); j++){
                indeg[adj[i][j]]++;
            }
            flag = 1;
        }
    }

    if(!flag){
        for(int i = 0; i < ans.size(); i++){
            printf("%d ", ans[i]);
        }
        cout<<endl;
    }
}
int main()
{
    scanf("%d%d", &n, &m);

    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        indeg[v]++;
    }

    alltopsort();
}
