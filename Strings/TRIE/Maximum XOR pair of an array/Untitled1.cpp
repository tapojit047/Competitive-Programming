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

const int K = 2;

/// https://www.youtube.com/watch?v=jCu-Pd0IjIA
/// https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array-set-2/

bool checkbit(int mask, int bit)
{
    return (mask & (1<<bit));
}

struct Vertex
{
    int next[K];
    bool leaf = 0;

    Vertex()
    {
        RESET(next, -1);
    }
};
//vector <Vertex> trie(1);
vector <Vertex> trie;
int ara[MX];

void Insert(int val)
{
    int cur = 0;
    for(int i = 30; i >= 0; i--){
        int x = checkbit(val, i);
        if(trie[cur].next[x] == -1){
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[x];
    }
    trie[cur].leaf = 1;
}

int Search(int val)
{
    int cur = 0, ans = 0;
    for(int i = 30; i >= 0; i--){
        int x = checkbit(val, i);

        if(trie[cur].next[!x] != -1){
            ans |= (1<<i);
            cur = trie[cur].next[!x];
        }
        else{
            cur = trie[cur].next[x];
        }
    }
    return ans;
}

void solve()
{
    /// creating the root
    trie.emplace_back();

    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ara[i];
        Insert(ara[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, Search(ara[i]));
    }
    cout<<ans<<endl;
    trie.clear();
}

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
