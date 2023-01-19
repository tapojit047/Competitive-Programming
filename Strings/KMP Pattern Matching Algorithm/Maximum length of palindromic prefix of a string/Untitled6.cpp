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
string str;
int n;
vector <int> pi;

void prefix_function(string pattern)
{
    pi.resize(pattern.size());
    for(int i = 1; i < pattern.size(); i++){
        int j = pi[i-1];
        while(j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
}

void solve()
{
    string temp;
    cin>>temp;
    str = temp;
    reverse(temp.begin(), temp.end());
    str += "#";
    str += temp;

    prefix_function(str);

    int ans = pi.back();
    cout<<"Case "<<Case++<<": ";
    cout<<ans<<endl;
}

///Maximum length of palindromic prefix of a string

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
