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

#define        MX        100005
#define        SQRSIZE   405

const ll max_val = 10000000000;

int n, m;
int ara[MX];
int block[SQRSIZE];
int blk_sz;

void build()
{
    for(int i = 0; i < n/blk_sz; i++) block[i] = INT_MAX;

    for(int i = 0; i < n; i++){
        int blk_num = (i/blk_sz);
        block[blk_num] = min(block[blk_num], ara[i]);
    }
}
int query(int l, int r)
{
     l--, r--; //comment if '0' based indexing is used in the question
    int ans = INT_MAX;
    while((l%blk_sz) != 0 && l<r){
        ans = min(ans, ara[l]);
        l++;
    }

    while(l+blk_sz <= r){
        int blk_num = (l/blk_sz);
        ans = min(ans, block[blk_num]);
        l += blk_sz;
    }

    while(l <= r){
        ans = min(ans, ara[l]);
        l++;
    }
    return ans;
}
void update(int p, int val)
{
    p--; //comment if '0' based indexing is used in the question
    ara[p] = val;
    int blk_num = (p/blk_sz);
    block[blk_num] = INT_MAX;
    int l = blk_num, r = blk_num+blk_sz-1;

    for(int i = l; i <= r; i++){
        block[blk_num] = min(block[blk_num], ara[i]);
    }
}
int main()
{
    optimize
    cin>>n;
    blk_sz = sqrt(n);

    for(int i = 0; i < n; i++) cin>>ara[i];
    build();

    cin>>m;
    while(m--){
        //complexity per query is O(sqrt(n))
        int p;
        cin>>p;
        if(p == 1){
            int l, r;
            cin>>l>>r;
            cout<<query(l, r)<<endl;
        }
        else{
            int i, val;
            cin>>i>>val;
            update(i, val);
        }
    }
}
