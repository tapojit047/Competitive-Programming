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

#define        MX        200005
#define        max_val   1000005

int n, m;
int blk_sz;
int ans[MX];
int ara[MX];
int freq[max_val];
int c = 0;

struct X
{
    int L, R, idx;
};
bool func(X a, X b)
{
    if((a.L/blk_sz) != (b.L/blk_sz)){
        return a.L/blk_sz < b.L/blk_sz;
    }
    return a.R < b.R;
}
X query[MX];
void add(int i)
{
    freq[ara[i]]++;
    if(freq[ara[i]] == 1){
        c++;
    }
}
void Remove(int i)
{
    freq[ara[i]]--;
    if(freq[ara[i]] == 0){
        c--;
    }
}
void MO()
{
    blk_sz = sqrt(n);
    sort(query, query+m, func);

    int curL = 0, curR = -1, curSum = 0;
    for(int i = 0; i < m; i++){
        int L = query[i].L, R = query[i].R;
        //extending
        while(curL > L){
            curL--;
            add(curL);
        }
        while(curR < R){
            curR++;
            add(curR);
        }
        //reducing
        while(curL < L){
            Remove(curL);
            curL++;
        }
        while(curR > R){
            Remove(curR);
            curR--;
        }

        ans[query[i].idx] = c;
    }
}
int main()
{
    optimize
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];

    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>query[i].L>>query[i].R;
        query[i].L--, query[i].R--; //If 1 based indexing then uncomment
        query[i].idx = i;
    }

    MO();
    for(int i = 0; i < m; i++){
        cout<<ans[i]<<endl;
    }
}
