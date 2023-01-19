#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define piii pair < int, pair <int, int> >
#define RESET(a, b) memset(a, b, sizeof(a))

bool visited[105];
vector < piii > edges;
vector < piii> MST;
int m1, m2, M, N, ROOT[105];

void initialize()
{
    for(int i = 1; i <= N; i++){
        ROOT[i] = i;
    }
}

int root(int x)
{
    while(x != ROOT[x]){
        x = ROOT[ROOT[x]];
    }
    return x;
}
void uni(int x, int y)
{
    int r1 = root(x);
    int r2 = root(y);
    ROOT[r1] = ROOT[r2];
}
int kruskal()
{
    int mincost = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].s.f;
        int v = edges[i].s.s;
        int w = edges[i].f;

        if(root(u) != root(v)){
            uni(u, v);
            mincost += w;
            MST.push_back(mp(w, mp(u, v)));
        }
    }
    return mincost;
}
int kruskal1()
{
    int mini = -1;

    for(int j = 0; j < MST.size(); j++){

        int mincost = 0, c = 0;

        RESET(visited, 0);
        initialize();
        //cout<<MST[j].f<<' '<<MST[j].s.f<<' '<<MST[j].s.s<<endl;

        for(int i = 0; i < edges.size(); i++){
            //cout<<1<<endl;
            if(edges[i].f == MST[j].f && edges[i].s.f == MST[j].s.f && edges[i].s.s == MST[j].s.s){
                continue;
            }
            //cout<<w<<endl;
            int u = edges[i].s.f;
            int v = edges[i].s.s;
            int w = edges[i].f;

            if(root(u) != root(v)){
                uni(u, v);
                if(!visited[u]){
                    c++;
                    visited[u] = 1;
                }
                if(!visited[v]){
                    c++;
                    visited[v] = 1;
                }
                mincost += w;
            }
        }
        //cout<<mincost<<' '<<c<<endl;
        if(c == N && mincost >= m1){
            if(mini == -1 || mincost < mini){
                mini = mincost;
            }
        }
        //cout<<mini<<endl;
    }
    return mini;

//    return mincost;
}
int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++){
        scanf("%d%d", &N, &M);

        for(int i = 0; i < M; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(mp(w, mp(u, v)));
        }
        sort(edges.begin(), edges.end());
        initialize();
        m1 = kruskal();
        //cout<<m1<<endl;
        initialize();
        m2 = kruskal1();

        if(m2 == -1){
            m2 = m1;
        }
        printf("%d %d\n", m1, m2);
        MST.clear();
        edges.clear();
    }
}
