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

int K = 25; /// log2(1e7)
ll ara[MX];
ll st[MX][26];
int n, m;

void precomp()
{
    for(int i = 0; i < n; i++) st[i][0] = ara[i];
    for(int j = 1; j <= 25; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
        }
    }
    ///O(n*log(n))
}

ll query(int L, int R)
{
    ll ans = 0;
    for(int j = K; j >= 0; j--){
        if((1 << j) <= (R-L+1)){
            ans += st[L][j];
            L += (1 << j);
        }
    }
    return ans;
    ///O(log(n))
}

int main()
{
    optimize
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }

    cin>>m;
    precomp();
    while(m--){
        int l, r;
        cin>>l>>r;
        cout<<query(l-1, r-1)<<endl;
    }
}
