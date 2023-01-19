#include<bits/stdc++.h>
using namespace std;
#define mx 2005
#define inf 100000000
#define RESET(a, b) memset(a, b, sizeof(a))

struct EDGE
{
    int u, v, w;
};

EDGE edges[mx];
int N, M, dis[mx];

bool bellman()
{
    RESET(dis, inf);
    dis[0] = 0;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dis[edges[j].v] > dis[edges[j].u]+edges[j].w){
                dis[edges[j].v] = dis[edges[j].u] + edges[j].w;
            }
        }
    }
    //negative cycle
    for(int j = 0; j < M; j++){
        if(dis[edges[j].v] > dis[edges[j].u]+edges[j].w){
            return true;
            dis[edges[j].v] = dis[edges[j].u] + edges[j].w;
        }
    }
    return false;
}
int main()
{
    int T, a, b, c;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);

        for(int i = 0; i < M; i++){

            scanf("%d%d%d", &a, &b, &c);
            edges[i].u = a;
            edges[i].v = b;
            edges[i].w = c;
        }
        if(bellman()){
            printf("possible\n");
        }
        else{
            printf("not possible\n");
        }
    }
}
