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

ll segmented_sieve(ll a, ll b)
{
    if(a == 1) a++;

    ll dif = b-a+1;
    vector <bool> chk(dif);
    ll i, j;
    for(int i = 0; i < prime.size(); i++){
        ll p = prime[i];
        if(p*p > b) break;
        j = p*p;
        if(j < a) j = ((a+p-1)/p)*p;
        for(; j <= b; j += p) chk[j-a] = 1;
    }

    ll ans = 0;
    for(int i = 0; i < dif; i++) if(!chk[i]) ans++;
    return ans;
    ///O(n*log2(log2(n))
}

/// Segemented Sieve is used for calculating number of primes in a segment (a, b <= 10^12) && (b-a) <= 10^5
/// It is almost same as sieve. We have to do the same thing as we do in sieve but in a different range

int main()
{
    optimize
    sieve(1e6);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        ll ans = segmented_sieve(a, b);

        cout<<"Case "<<Case++<<": ";
        cout<<ans<<endl;
    }
}
