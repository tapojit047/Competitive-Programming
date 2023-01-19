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

ll tree[MX*4];

ll query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];

    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (b+e)>>1;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i)
{
    if(b > i || e < i) return;
    if(b >= i && e <= i){
        tree[node]++;
        return;
    }

    int left = (node<<1);
    int right = (node<<1)+1;
    int mid = (b+e)>>1;

    update(left, b, mid, i);
    update(right, mid+1, e, i);

    tree[node] = tree[left]+tree[right];
}

///Number of swaps needed to change a string to other one or number of swaps needed to swap a permutation

int main()
{
    optimize
    string str;
    int n;
    cin>>n;
    cin>>str;

    string res = str;
    reverse(res.begin(), res.end());

    queue <int> pos[200];
    for(int i = 0; i < n; i++){
        pos[res[i]].push(i+1);
    }
    vector <int> ara;
    for(int i = 0; i < str.size(); i++){
        int x = pos[str[i]].front();
        pos[str[i]].pop();
        ara.push_back(x);
    }

    ll ans = 0;
    for(auto x: ara){
        ll cur = query(1, 1, n, x, n);
        ans += cur;
        update(1, 1, n, x);
    }
    cout<<ans<<endl;

}
