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

int ara[MX];

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>ara[i];
        }

        set <int> s1, s2;
        for(int i = 1; i <= n; i++){
            s1.insert(i);
            s2.insert(i);
        }

        vector <int> maxim, minim;
        for(int i = 0; i < n; i++){
            if(!i || ara[i] != ara[i-1]){
                s1.erase(ara[i]);
                s2.erase(ara[i]);
                maxim.push_back(ara[i]);
                minim.push_back(ara[i]);
            }
            else{
                auto it = s2.lower_bound(ara[i]);
                it--;
                maxim.push_back(*it);
                minim.push_back(*s1.begin());

                s1.erase(s1.begin());
                s2.erase(it);
            }
        }
        for(auto x: minim) cout<<x<<' ';
        cout<<endl;
        for(auto x: maxim) cout<<x<<' ';
        cout<<endl;

    }
}
