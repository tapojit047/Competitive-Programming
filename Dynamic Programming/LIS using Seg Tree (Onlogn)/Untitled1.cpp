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
const int inf = 2e9;

pii ara[MX];
int tree[MX*4];

//void build(int node, int b, int e)
//{
//    if(b == e){
//        tree[node] = ara[b];
//        return;
//    }
//
//    int left = (node<<1);
//    int right = (node<<1) + 1;
//    int mid = (b+e)>>1;
//
//    build(left, b, mid);
//    build(right, mid+1, e);
//
//    tree[node] = max(tree[left], tree[right]);
//}

int query(int node, int b, int e, int i, int j)
{
    if(j < i) return 0;
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    int ans = max(p1, p2);
    return ans;
}

void update(int node, int b, int e, int i, int newval)
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

bool func(pii &a, pii &b)
{
    return (a.second < b.second);
}

int main()
{
    optimize
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>ara[i].first;
        ara[i].second = i;
    }

    sort(ara, ara+n);

    int c = 1, prev;
    for(int i = 0; i < n; i++){

        if(!i) prev = ara[i].first, ara[i].first = c;
        else if(ara[i].first == prev) ara[i].first = c;
        else{
            prev = ara[i].first;
            c++;
            ara[i].first = c;
        }
    }

    sort(ara, ara+n, func);
    int ans = 1;
    for(int i = 0; i < n; i++){
        int p = query(1, 1, n, 1, ara[i].first-1);
        int cur = p+1;
        ans = max(ans, cur);

        update(1, 1, n, ara[i].first, cur);
    }
    cout<<ans<<endl;
}
