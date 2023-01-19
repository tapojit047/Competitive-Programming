#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mx 1000005

typedef long long ll;

ll n, m;

pair <ll, pair <int, int> > edges[mx];

ll ROOT[mx];

void initialize()
{
    for(int i = 1; i <= n; i++){
        ROOT[i] = i;
    }
}

ll root(ll x)
{
    while(ROOT[x] != x){

        ROOT[x] = ROOT[ROOT[x]];

        x = ROOT[x];
    }
    return x;
}

void uni(ll x, ll y)
{
    ll r1 = root(x);
    ll r2 = root(y);
    ROOT[r2] = ROOT[r1];
}

ll kruskal()
{
    ll mincost = 0;

    for(int i = 0; i < m; i++){

        ll x = edges[i].s.f;
        ll y = edges[i].s.s;
        ll w = edges[i].f;

       // cout<<x<<' '<<y<<endl;
       // cout<<root(x)<<' '<<root(y)<<endl<<endl;

        if(root(x) != root(y)){
            uni(x, y);
            mincost += w;
        }
    }
    return mincost;
}
int main()
{
    scanf("%lld%lld", &n, &m);

    for(int i = 0; i < m; i++){
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        edges[i] = make_pair(w, make_pair(u, v));
    }

    initialize();

    sort(edges, edges+m);

    ll mincost = kruskal();
    printf("%lld\n", mincost);

}
