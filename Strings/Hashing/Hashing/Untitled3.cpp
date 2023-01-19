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

const ll MX = 1e6 + 105;

const ll p1 = 737; ///base 1
const ll p2 = 3079; ///base 2
const ll m1 = 1000000123;
const ll m2 = 1000000321;

pair <ll, ll> Hash(string str)
{
    ll H1 = 0, H2 = 0;
    ll pro1 = 1, pro2 = 1;
    for(int i = 0; i < str.size(); i++){
        H1 = (H1 + (str[i] - 'a' + 1)*pro1) % m1;
        H2 = (H2 + (str[i] - 'a' + 1)*pro2) % m2;

        pro1 = (pro1 * p1) % m1;
        pro2 = (pro2 * p2) % m2;
    }
    return {H1, H2};
}

void solve()
{
    string str;
    cin>>str;
    pii H = Hash(str);
    cout<<H.first<<' '<<H.second<<endl;
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
