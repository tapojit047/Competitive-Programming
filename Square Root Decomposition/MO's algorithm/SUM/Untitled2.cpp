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

int n, m;
int blk_sz;
ll ans[MX];
ll ara[MX];

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

void MO()
{
    blk_sz = sqrt(n);
    sort(query, query+m, func);

    int curL = 0, curR = -1, curSum = 0;
    for(int i = 0; i < m; i++){
        int L = query[i].L, R = query[i].R;
        while(curL > L){
            curL--;
            curSum += ara[curL];
        }
        while(curR < R){
            curR++;
            curSum += ara[curR];
        }
        while(curL < L){
            curSum -= ara[curL];
            curL++;
        }
        while(curR > R){
            curSum -= ara[curR];
            curR--;
        }

        ans[query[i].idx] = curSum;
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
        //query[i].L--, query[i].R--; //If 1 based indexing then uncomment
        query[i].idx = i;
    }
    MO();
    for(int i = 0; i < m; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}

