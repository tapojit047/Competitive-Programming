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

const ll MX = 2e5 + 105;

bool check(int x)
{
    if((x%3 == 0) || (x%10 == 3)) return 0;

    return 1;
}

int main()
{
    optimize
    vector <int> ans;
    for(int i = 1; ans.size() < 1000; i++){
        if(check(i)) ans.push_back(i);
    }
//    for(auto x: ans) cout<<x<<' ';
//    cout<<endl;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<ans[x-1]<<endl;
    }
}
