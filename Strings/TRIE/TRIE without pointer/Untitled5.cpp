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

const int K = 26;

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

void Insert(string str)
{
    int cur = 0;
    for(auto ch: str){
        int x = ch-'a';
        if(trie[cur].next[x] == -1){
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[x];
    }
    trie[cur].leaf = 1;
}

bool Search(string str)
{
    int cur = 0;
    for(auto ch: str){
        int x = ch-'a';
        if(trie[cur].next[x] == -1) return 0;
        cur = trie[cur].next[x];
    }
    return trie[cur].leaf;
}

void solve()
{
    /// creating the root
    trie.emplace_back();

    int n, m;
    cin>>n;
    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        Insert(str);
    }
    cin>>m;
    while(m--){
        string str;
        cin>>str;
        if(Search(str)){
            YES;
        }
        else{
            NO;
        }
    }
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
