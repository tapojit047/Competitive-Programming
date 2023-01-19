#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

#define sum first
#define prop second

ll ara[MX];
pll tree[MX];

void build(int node, int b, int e)
{
    if(b == e){
        tree[node].sum = ara[b];
        return;
    }
    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, ll addval)
{
    if(i > e || b > j) return;
    if(b >= i && e <= j){
        tree[node].sum += (e-b+1)*addval;
        tree[node].prop += addval;
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i, j, addval);
    update(right, mid+1, e, i, j, addval);

    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry)
{
    if(i > e || b > j) return 0LL;
    if(b >= i && e <= j) return tree[node].sum+carry*(e-b+1);

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    ll p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    optimize
    int n, m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++) cin>>ara[i];
    build(1, 1, n);

    while(m--){
        int p;
        cin>>p;
        if(p == 1){
            int l, r, addval;
            cin>>l>>r>>addval;
            update(1, 1, n, l, r, addval);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<query(1, 1, n, l, r, 0LL)<<endl;
        }
    }
}
