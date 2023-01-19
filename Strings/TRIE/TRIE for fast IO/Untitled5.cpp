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

const int K = 52;
int Case = 1;

struct Vertex
{
    int next[K];
    int leaf = 0;

    Vertex()
    {
        RESET(next, -1);
    }
};
//vector <Vertex> trie(1);
vector <Vertex> trie;

int value(char ch)
{
    if(ch >= 'a' && ch <= 'z') return (ch-'a');
    int val = ch-'A'+26;
    return val;
}

void Insert(char str[])
{
    int cur = 0;
    for(int i = 0; i < strlen(str); i++){
        int x = value(str[i]);
        if(trie[cur].next[x] == -1){
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[x];
    }
    trie[cur].leaf++;
}

int Search(string str)
{
    int cur = 0;
    for(auto ch: str){
        int x = value(ch);
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
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char str[101];
        scanf("%s", str);

        int n = strlen(str);
        if(n > 2) sort(str+1, str+n-1);
//        error(str);
        Insert(str);
    }

    scanf("%d", &m);

    printf("Case %d:\n", Case++);
    while(m--){
        char str[10005];

        getchar();
        scanf("%[^\n]s", str);
        string cur;
        int ans = 1;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == ' '){
                if(cur.size()){
                    if(cur.size() > 2) sort(cur.begin()+1, cur.end()-1);
                    int x = Search(cur);
                    ans *= x;
                }
                cur.clear();
            }
            else cur += str[i];
        }
        if(cur.size()){
            if(cur.size() > 2) sort(cur.begin()+1, cur.end()-1);
            int x = Search(cur);
            ans *= x;
        }
        printf("%d\n", ans);
    }
    trie.clear();
}

/// https://lightoj.com/problem/easily-readable

int main()
{
//    optimize
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}
