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

const ll MX = 2e5 + 105;
const ll inf = 2e9 + 105;

string str;
int dp[105][105][2];

///Maximize the result of an arithmetic expression consists of digits, '+' and '*' and '-', inserting brackets

///1->max 0->min

int func(int b, int e, bool maxormin)
{
    int &res = dp[b][e][maxormin];
    if(res != -1) return res;
    if(b == e) return (str[b]-'0');
//    if(b > e) return 0;

    if(maxormin) res = -inf;
    else res = inf;
    for(int i = b+1; i < e; i++){
        if(str[i] >= '0' && str[i] <= '9') continue;

        int val1, val2, val;
        if(str[i] == '-'){
            val1 = func(b, i-1, maxormin);
            val2 = func(i+1, e, !maxormin);
        }
        else{
            val1 = func(b, i-1, maxormin);
            val2 = func(i+1, e, maxormin);
        }

        if(str[i] == '-') val = val1 - val2;
        else if(str[i] == '+') val = val1 + val2;
        else val = val1 * val2;

        if(maxormin) res = max(res, val);
        else res = min(res, val);
    }
    return res;
}

int main()
{
    optimize
    cin>>str;

    RESET(dp, -1);
    cout<<func(0, str.size()-1, 1)<<endl;
}
