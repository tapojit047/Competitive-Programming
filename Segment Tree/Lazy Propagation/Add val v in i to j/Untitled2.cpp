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
#define pll pair <ll, ll>
#define gcd(a, b) __gcd(a, b)

#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

#define        MX        100005
#define sum first
#define prop second

ll Case = 1;
ll ara[MX];
pll tree[4*MX];

void build(ll node, ll b, ll e)
{
    if(b == e){
        tree[node].sum = ara[b];
        tree[node].prop = 0;
        return;
    }
    ll left = (node<<1);
    ll right = (node<<1)+1;
    ll mid = (b+e)>>1;

    build(left, b, mid);
    build(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop = 0;
}

void update(ll node, ll b, ll e, ll i, ll j, ll addval, ll pro)
{
    if(i > e || b > j){
        tree[node].sum += (e-b+1)*pro;
        tree[node].prop += pro;
        return;
    }
    if(b >= i && e <= j){
        tree[node].sum += (e-b+1)*(addval+pro);
        tree[node].prop += (addval+pro);

        return;
    }

    ll left = (node<<1);
    ll right = (node<<1)+1;
    ll mid = (b+e)>>1;

    update(left, b, mid, i, j, addval, pro+tree[node].prop);
    update(right, mid+1, e, i, j, addval, pro+tree[node].prop);

    tree[node].prop = 0;
    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry)
{
    if(i > e || b > j) return 0;
    if(b >= i && e <= j){
        return ((e-b+1)*carry)+tree[node].sum;
    }

    ll left = (node<<1);
    ll right = (node<<1)+1;
    ll mid = (b+e)>>1;

    ll p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    optimize
//    WRITE
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        build(1, 1, n);

        cout<<"Case "<<Case++<<":"<<endl;
        while(m--){
            ll p;
            cin>>p;
            if(p == 1){
                ll l, r, addval;
                cin>>l>>r>>addval;
                l++, r++;
                update(1, 1, n, l, r, addval, 0);
//                for(ll i = 1; i <= 25; i++){
//                    error(i, tree[i].sum, tree[i].prop);
//                }
            }
            else{
                ll l, r;
                cin>>l>>r;
                l++, r++;
                ll lob = query(1, 1, n, l, r, 0);
                ll hor = (r-l+1);
//                error(lob, hor);
                ll g = gcd(lob, hor);
                lob /= g;
                hor /= g;
                if(hor == 1) cout<<lob<<endl;
                else cout<<lob<<"/"<<hor<<endl;
            }
        }
        for(ll i = 1; i <= 4*n; i++) tree[i].sum = 0, tree[i].prop = 0;
    }
}
//100
//8 5
//1 0 7 5
//1 2 5 10
//2 0 7
//2 1 5
//2 4 6
