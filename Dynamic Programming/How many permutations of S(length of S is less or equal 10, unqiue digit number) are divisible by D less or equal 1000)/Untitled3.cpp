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
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 1e3 + 105;

int dp[(1<<10)+2][MX];
int d;
string str;

int func(int mask, int mod)
{
    int &res = dp[mask][mod];

//    error(mask, mod, res);
    if(res != -1) return res;


    int pos = __builtin_popcount(mask);
//    error(mask, mod, res, pos);
    if(pos == str.size()){
        if(!mod) return 1;
        return 0;
    }

    res = 0;
    for(int i = 0; i < str.size(); i++){
//        error(i, mask & (1<<i));
        if(mask & (1<<i)) continue;
        res += func(mask | (1<<i), (mod*10 + (str[i]-'0')) % d);
    }
    return res;
}

///How many permutations of S(|S| <= 10, unqiue digit number) are divisible by D(<=1000)

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        cin>>str>>d;
        RESET(dp, -1);

        cout<<func(0, 0)<<endl;
    }
}
