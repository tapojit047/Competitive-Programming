#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
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
#define pii pair <ll, ll>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

const ll MX = 2e5 + 105;

ll ara[MX];

int main()
{
    optimize
    ll n, t;
    cin>>n>>t;

    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }

    new_data_set s;
    ll sum = 0, ans = 0;
    s.insert({-t, s.size()});
    for(int i = 0; i < n; i++){
        sum += ara[i];

        ll dis = s.order_of_key({-sum, -1});
        ans += dis;
        s.insert({-(t+sum), s.size()});
    }
    cout<<ans<<endl;
}
