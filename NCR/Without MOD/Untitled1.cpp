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

ll Left[MX], Right[MX];
ll ara[MX];

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>ara[i];
        }
        Left[0] = ara[0];
        ll p = 0;
        bool no = 0;
        for(int i = 1; i < n; i++){
            Left[i] = min(Left[i-1], ara[i]);
            if(ara[i] < p){
                no = 1;
                break;
            }
            if(ara[i]-Left[i] < p){
                Left[i] = ara[i]-p;
                ara[i] = p;
            }
            else ara[i] -= Left[i];
            p = max(p, ara[i]);
        }
//        for(int i = 0; i < n; i++) cout<<ara[i]<<' ';
//        cout<<endl;

        Right[n-1] = ara[n-1];
        for(int i = n-2; i > 1; i--){
            Right[i] = min(Right[i+1], ara[i]);
            ara[i] -= Right[i];
            if(ara[i]){
                no = 1;
                break;
            }
        }

        if(no){
            NO;
        }
        else{
            YES;
        }
    }
}
