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
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)

#define cnt first
#define minim second
const ll inf = -1e18 + 10;

#define        MX        200005

ll ara[MX];
ll tree[MX*4];

void build(int node, int b, int e)
{
    if(b == e){
        tree[node] = ara[b];
        return;
    }

    int left = (node<<1);
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node] = max(tree[left], tree[right]);
}

ll query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return  inf;
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);

    ll ans = max(p1, p2);
    return ans;
}

void update(int node, int b, int e, int i, ll newval)
{
    if(b > i || e < i) return;
    if(b >= i && e <= i){
        tree[node] = newval;
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i, newval);
    update(right, mid+1, e, i, newval);

    tree[node] = max(tree[left], tree[right]);
}

int main()
{
    /////In this code indexing is done in 1 to n, both for tree and the array
    optimize
    ll n, m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++) cin>>ara[i];

    build(1, 1, n);

    while(m--){
        int p;
        cin>>p;
        if(p == 1){
            int i; ll v;
            cin>>i>>v;
            update(1, 1, n, i, v);
        }
        else{
            int l, r;
            cin>>l>>r;
            ll ans = query(1, 1, n, l, r);
            cout<<ans<<endl;
        }
    }
}
