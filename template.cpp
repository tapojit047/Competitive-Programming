#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define       

int dx[5] = {+1, +0, -1, -0};
int dy[5] = {+0, +1, -0, -1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
inline ll checkBit(ll n, int i) { return n&(1ll<<i); }
inline void setBit(ll &n, int i) { n |= (1ll<<i); }
inline void resetBit(ll &n, int i) { n &= ~(1ll<<i); }

const double eps = 1e-9;
inline bool Equal(double x, double y) { return fabs(x-y)<eps; }
inline bool Greater(double x, double y){ return x-eps>y; }
inline bool Lesser(double x, double y){ return x+eps<y; }

///possible to calculate primes till 10^7
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

///possible to calculate primes till 10^12
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


