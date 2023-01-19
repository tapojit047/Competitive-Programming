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

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        ll N;
        cin>>N;

        ///a = m*m-n*n
        ///b = 2mn
        ///c = m*m+n*n
        ///where m and n are two integers (n < m) and in triple a, b, c (a < b < c)
        ll m = 2;
        ll a, b, c = 0, ans = 0, triple = 0;;

        while(c < N){
            for(ll n = m-1; n < m; n++){
                b = 2*m*n;
                a = m*m-n*n;
                c = m*m+n*n;

                if(c > N) break;

//                ll p = a*a-b;
//                if(c == p) ans++;
////                error(a, b, c, p, ans);
                triple++;
            }
            m++;
        }
        cout<<triple<<endl;

    }
}
