#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define maxim first
#define minim second

const ll inf = 1e18 + 10;

#define        MX        200005

ll ara[MX];
pair <ll, ll> tree[MX*4];

void build(int node, int b, int e)
{
    if(b == e){
        tree[node].maxim = ara[b];
        tree[node].minim = ara[b];
        return;
    }

    int left = (node<<1);
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node].maxim = max(tree[left].maxim, tree[right].maxim);
    tree[node].minim = min(tree[left].minim, tree[right].minim);
}

pair <ll, ll> query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return {-inf, inf};
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    pair <ll, ll> p1 = query(left, b, mid, i, j);
    pair <ll, ll> p2 = query(right, mid+1, e, i, j);

    pair <ll, ll> ans;
    ans.maxim = max(p1.maxim, p2.maxim);
    ans.minim = min(p1.minim, p2.minim);
    return ans;
}

void update(int node, int b, int e, int i, ll newval)
{
    if(b > i || e < i) return;
    if(b >= i && e <= i){
        tree[node].maxim = newval;
        tree[node].minim = newval;
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i, newval);
    update(right, mid+1, e, i, newval);

    tree[node].maxim = max(tree[left].maxim, tree[right].maxim);
    tree[node].minim = max(tree[left].minim, tree[right].minim);
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
