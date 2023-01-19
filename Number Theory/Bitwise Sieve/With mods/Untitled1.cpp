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

const ll MX = 1e7 + 105;

bool Check(int mask, int bit) { return (mask & (1<<bit)); }
int Set(int mask, int bit) { return (mask | (1<<bit)); }

int chk[MX];
vector <int> prime;
void sieve(int n)
{
    int i, j;
    for(i = 4; i <= n; i += 2) chk[i>>5] = Set(chk[i>>5], i&31);

    for(i = 3; ll(i)*ll(i) <= ll(n); i++){
        if(Check(chk[i>>5], i&31)) continue;
        for(j = i*i; j <= n; j += i){
            chk[j>>5] = Set(chk[j>>5], j&31);
        }
    }
    for(int i = 2; i <= n; i++) if(!Check(chk[i>>5], i&31)) prime.push_back(i);
    ///O(n*log2(log2(n))
}

int main()
{
    optimize
    sieve(100000000);

    for(int i = 0; i < prime.size(); i+=100) cout<<prime[i]<<endl;
}
