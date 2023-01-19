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

const int MX = 2e5 + 105;
const int inf = INT_MAX;

int ara[MX];
int Left[MX], Right[MX];

///Left or right nearest smallest number for a element in an array in O(n) using stack

int main()
{
    optimize
    int n, m;
    cin>>n;

    vector <pii> s;
    for(int i = 1; i <= n; i++){
        cin>>ara[i];
        s.push_back({ara[i], i});
    }
    sort(s.begin(), s.end());

    stack <int> st;
    for(int i = 1; i <= n; i++){
        while(1){
            if(st.empty()){
                Left[i] = 0;
                break;
            }
            else if(ara[st.top()] >= ara[i]){
                st.pop();
            }
            else{
                Left[i] = st.top();
                break;
            }
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n; i > 0; i--){
        while(1){
            if(st.empty()){
                Right[i] = n+1;
                break;
            }
            else if(ara[st.top()] >= ara[i]){
                st.pop();
            }
            else{
                Right[i] = st.top();
                break;
            }
        }
        st.push(i);
    }
    ///Left nearest smallest number
    for(int i = 1; i <= n; i++){
        cout<<Left[i]<<' ';
    }
    cout<<endl;
    ///Right nearest smallest number
    for(int i = 1; i <= n; i++){
        cout<<Right[i]<<' ';
    }
    cout<<endl;
}
