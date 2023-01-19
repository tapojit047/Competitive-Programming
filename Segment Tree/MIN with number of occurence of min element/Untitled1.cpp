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
const ll inf = 1e10;

#define        MX        200005

ll ara[MX];
pii tree[MX*4];

void build(int node, int b, int e)
{
    if(b == e){
        tree[node] = pii(1, ara[b]);
        return;
    }

    int left = (node<<1);
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node].minim = min(tree[left].minim, tree[right].minim);
    tree[node].cnt = 0;

    if(tree[node].minim == tree[left].minim) tree[node].cnt += tree[left].cnt;
    if(tree[node].minim == tree[right].minim) tree[node].cnt += tree[right].cnt;
}

pii query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return pii(0, inf);
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    pii p1 = query(left, b, mid, i, j);
    pii p2 = query(right, mid+1, e, i, j);

    pii ans; ans.cnt = 0;
    ans.minim = min(p1.minim, p2.minim);

    if(ans.minim == p1.minim) ans.cnt += p1.cnt;
    if(ans.minim == p2.minim) ans.cnt += p2.cnt;
    return ans;
}

void update(int node, int b, int e, int i, ll newval)
{
    if(b > i || e < i) return;
    if(b >= i && e <= i){
        tree[node] = pii(1, newval);
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i, newval);
    update(right, mid+1, e, i, newval);

    tree[node].minim = min(tree[left].minim, tree[right].minim);
    tree[node].cnt = 0;

    if(tree[node].minim == tree[left].minim) tree[node].cnt += tree[left].cnt;
    if(tree[node].minim == tree[right].minim) tree[node].cnt += tree[right].cnt;
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
            pii ans = query(1, 1, n, l, r);
            cout<<ans.minim<<' '<<ans.cnt<<endl;
        }
    }
}
