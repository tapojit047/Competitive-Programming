#include<bits/stdc++.h>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))
#define mx 10005
#define wt first
#define node second
#define pii pair<int, int>
#define inf 100000000

vector <pii> adj[mx];

int C, S, Q, cost[mx], parent[mx];

bool visited[mx];
bool uhu[mx];

void prims(int s)
{
    RESET(visited, 0);
    RESET(cost, -1);
    RESET(parent, -1);

    priority_queue < pii, vector <pii>, greater <pii> > q;

    q.push(pii(0, s));

    cost[s] = 0;

    while(!q.empty()){

        int x = q.top().node;
        int w = q.top().wt;
        q.pop();

        if(uhu[x]){
            continue;
        }
	uhu[x] = 1;
        visited[x] = 1;

        for(int i = 0; i < adj[x].size(); i++){

            int v = adj[x][i].node;
            int vwt = adj[x][i].wt;

            if(!visited[v]){
                q.push(adj[x][i]);
		visited[x] = 1;
            }
        }
    }
}


int main()
{
    int t = 0;
    while(1){

        scanf("%d%d%d", &C, &S, &Q);

        if(!C && !S && !Q){
            break;
        }

        if(t){
            printf("\n");
        }

        t++;
        for(int i = 0; i < S; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);

            adj[u].push_back(pii(w, v));
            adj[v].push_back(pii(w, u));
        }

        printf("Case #%d\n", t);

        for(int i = 0; i < Q; i++){
            int u, v;
            scanf("%d%d", &u, &v);

            prims(u);

            if(cost[v] == -1){
                printf("no path\n");
            }
            else{
                printf("%d\n", cost[v]);
            }
        }

        for(int i = 1; i <= C; i++){
            adj[i].clear();
        }
    }
}
