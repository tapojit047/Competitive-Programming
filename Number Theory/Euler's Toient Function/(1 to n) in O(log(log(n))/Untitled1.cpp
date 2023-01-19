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

vector<int> phi;
void phi_1_to_n(int n)
{
    for(int i = 0; i <= n; i++) phi.push_back(i);
    //phi[0] = 0, phi[1] = 1;

    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j+=i){
                phi[j] -= (phi[j]/i);
            }
        }
    }
    ///O(n*log(log(n)))
}

int main()
{
    optimize
    phi_1_to_n(1e7);
}
