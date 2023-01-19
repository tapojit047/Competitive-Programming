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

int Case = 1;
ll ara[MX];
pll tree[4*MX];

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

void update(int node, int b, int e, int i, int j, ll addval, ll pro)
{
    if(i > e || b > j){
//        error(b, e, i, j, pro);
        if(pro == -1) return;
        tree[node].sum = (e-b+1)*pro;
        tree[node].prop = pro;
        return;
    }
    if(b >= i && e <= j){
        tree[node].sum = (e-b+1)*addval;
        tree[node].prop = addval;
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    ll p;
    if(pro != -1) p = pro;
    else p = tree[node].prop;

    update(left, b, mid, i, j, addval, p);
    update(right, mid+1, e, i, j, addval, p);

    tree[node].prop = -1;
    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(int node, int b, int e, int i, int j, ll carry)
{
    if(i > e || b > j) return 0LL;
    if(b >= i && e <= j){
        if(carry == -1) return tree[node].sum;
        else return (e-b+1)*carry;
    }

//    return tree[node].sum+carry*(e-b+1);

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    if(carry == -1){
        carry = tree[node].prop;
    }
    ll p1 = query(left, b, mid, i, j, carry);
    ll p2 = query(right, mid+1, e, i, j, carry);

    return p1+p2;
}

///https://lightoj.com/problem/computing-fast-average

int main()
{
    optimize
//    WRITE
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        build(1, 1, n);

        cout<<"Case "<<Case++<<":"<<endl;
        while(m--){
            int p;
            cin>>p;
            if(p == 1){
                int l, r, addval;
                cin>>l>>r>>addval;
                l++, r++;
                update(1, 1, n, l, r, addval, -1);
//                for(int i = 1; i <= 25; i++){
//                    error(i, tree[i].sum, tree[i].prop);
//                }
            }
            else{
                int l, r;
                cin>>l>>r;
                l++, r++;
                ll lob = query(1, 1, n, l, r, -1);
                ll hor = (r-l+1);
//                error(lob, hor);
                ll g = gcd(lob, hor);
                lob /= g;
                hor /= g;
                if(hor == 1) cout<<lob<<endl;
                else cout<<lob<<"/"<<hor<<endl;
            }
        }
        for(int i = 1; i <= 4*n; i++) tree[i].sum = 0, tree[i].prop = 0;
    }
}
//100
//8 5
//1 0 7 5
//1 2 5 10
//2 0 7
//2 1 5
//2 4 6
