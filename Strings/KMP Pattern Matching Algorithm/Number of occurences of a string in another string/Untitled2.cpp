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

/// Indexes of/number of occurrences of a pattern in a text

string pattern, text;
vector <int> pi;

void prefix_function()
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

void kmp()
{
    prefix_function();
//    for(auto x: pi) cout<<x<<' ';
//    cout<<endl;

    int n = pattern.size();
    bool yes = 0;
    vector <int> ans;

    for(int i = 0, j = 0; i < text.size(); i++){
//        error(i, j);
        if(j < n && text[i] == pattern[j]){
            j++;
        }
        else{
            while(j == n || (j > 0 && text[i] != pattern[j])){
                j = pi[j-1];
            }
            if(text[i] == pattern[j]) j++;
        }
        if(j == n){
            ans.push_back(i-n+1);
            yes = 1;
        }
    }
    if(!yes) cout<<"Not Found"<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto x: ans) cout<<x+1<<' ';
        cout<<endl;
    }
}

void solve()
{
    cin>>text;
    cin>>pattern;
    kmp();
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        solve();
        if(t) cout<<endl;
    }
}
