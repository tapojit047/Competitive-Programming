#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

#define        MX        200005
struct edge
{
    int cost, cnt;
    edge(int p, int q)
    {
        cost = p, cnt = q;
    }
};

bool operator<(edge a, edge b)
{
    return a.cost < b.cost;
}

int main()
{
    optimize
    priority_queue <edge> pq;
    pq.push(edge(10, 20));
    pq.push(edge(1, 2));
    pq.push(edge(11, 200));
    pq.push(edge(5, 50));
    pq.push(edge(100, 20));

    while(!pq.empty()){
        cout<<pq.top().cost<<' '<<pq.top().cnt<<endl;
        pq.pop();
    }
}
