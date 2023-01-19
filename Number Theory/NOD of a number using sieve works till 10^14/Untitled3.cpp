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

#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

const ll MX = 1e7 + 105;

int Case = 1;
bool chk[MX];
vector <int> prime;
void sieve(int n)
{
    int i, j;
    chk[1] = 1;
    for(i = 4; i <= n; i += 2) chk[i] = 1;
    for(i = 3; ll(i)*ll(i) <= ll(n); i++){
        if(chk[i]) continue;
        for(j = i*i; j <= n; j += i) chk[j] = 1;
    }
    for(int i = 2; i <= n; i++) if(!chk[i]) prime.push_back(i);
    ///O(n*log2(log2(n))
}

vector <int> primediv;
void factorize(ll n)
{
    for(int j = 0; j < prime.size(); j++){
        if(prime[j]*prime[j] > n) break;
        if(n % prime[j] == 0){
            int c = 0;
            while(n % prime[j] == 0) c++, n /= prime[j];
            primediv.push_back(c);
        }
    }
    if(n > 1) primediv.push_back(1);
    ///O(log2(n))
}

///Number of divisor of a number using sieve works till 10^12

int main()
{
//    optimize
//    WRITE
    sieve(1e7);
    int t;
//    cin>>t;
    scanf("%d", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);

        factorize(n);
        ll ans = 1;
        for(auto x: primediv){
//            error(x);
            ans *= (ll)(x+1);
        }
        printf("Case %d: %lld\n", Case++, ans-1);
        primediv.clear();
    }
}
