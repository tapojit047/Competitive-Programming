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

struct node
{
    bool endmark;
    node* next[30];
    node()
    {
        endmark = false;
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};
node *root;

void insert(string str)
{
    node *cur = root;
    for(int i = 0; i < str.size(); i++){
        int id = str[i]-'a';
        if(cur->next[id] == NULL){
            cur->next[id] = new node();
        }
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool search(string str)
{
    node* cur = root;
    for(int i = 0; i < str.size(); i++){
        int id = str[i]-'a';
        if(cur->next[id] == NULL) return 0;
        cur = cur->next[id];
    }
    return cur->endmark;
}

void del(node *cur)
{
    for(int i = 0; i < 26; i++){
        if(cur->next[i]){
            del(cur->next[i]);
        }
    }
    delete(cur);
}

int main()
{
    optimize
    int n;
    string str;
    root = new node();

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>str;
        insert(str);
    }

    int q;
    cin>>q;
    while(q--){
        cin>>str;
        if(search(str)){
            puts("FONUD");
        }
        else{
            puts("NOT FOUND");
        }
    }
}
