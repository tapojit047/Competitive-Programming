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
#define pint pair <int, int>
#define gcd(a, b) __gcd(a, b)

const int MX = 1e6 + 105;

int cnt[MX];
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
//    tree[node] = tree[left] + tree[right];
//}

void deleteKth(int node, int b, int e, int k)
{
    if(b == e){
        tree[node]--;
        cnt[b]--;
//        error(b, e, node, cnt[b]);
        return;
    }

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    if(tree[left] >= k){
        deleteKth(left, b, mid, k);
    }
    else{
        deleteKth(right, mid+1, e, k);
    }

    tree[node] = tree[left]+tree[right];
}

int ans;
void update(int node, int b, int e, int i)
{
    if(b > i || e < i) return;
    if(b >= i && e <= i){

        if(tree[node]) ans = i;
        cnt[i]++;
        tree[node]++;
//        error(b, e, node, cnt[i]);
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i);
    update(right, mid+1, e, i);

    tree[node] = tree[left]+tree[right];
}

int main()
{
    optimize
//    cout<<log(1e6)<<endl;
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        update(1, 1, n, x);
    }

//    build(1, 1, n);

    while(m--){
        int p;
//        cin>>p;
        scanf("%d", &p);
        if(p < 0){
            deleteKth(1, 1, n, abs(p));
        }
        else{
            update(1, 1, n, p);
        }
    }
    if(!tree[1]){
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        update(1, 1, n, i);
    }
    cout<<ans<<endl;
}
