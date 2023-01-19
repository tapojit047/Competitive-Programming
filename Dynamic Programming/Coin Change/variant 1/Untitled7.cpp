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


int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        vector <int> ara[200];

        set <char> s;
        for(int i = 0; i < str.size(); i++){
            ara[str[i]].push_back(i);
            s.insert(str[i]);
        }
//        for(int i = 'a'; i <= 'z'; i++){
//            cout<<(char)i<<": ";
//            for(auto x: ara[i]) cout<<x<<' ';
//            cout<<endl;
//        }
        string ans;
        int p = 0;
        vector <int> done;
        set <int> notpos;
        while(ans.size() < s.size()){
            for(int i = 'z'; i >= 'a'; i--){
                if(notpos.find(i) != notpos.end()) continue;
                if(ara[i].size() == 0) continue;
//                error(ans, (char)i, ans.size());
                bool check = 1;
                for(int j = i-1; j >= 'a'; j--){
                    if(ara[j].size() == 0) continue;
                    if(notpos.find(j) != notpos.end()) continue;
                    int l = lower_bound(ara[j].begin(), ara[j].end(), ara[i][0])-ara[j].begin();
//                    error((char)j, l, ara[j].size())

                    if(l == ara[j].size()){
                        check = 0;
                        break;
                    }
                }
                int l = lower_bound(done.begin(), done.end(), ara[i][0])-done.begin();
//                error((char)j, l, ara[j].size())
                if(check && l != done.size()){
                    notpos.insert(i);
                    check = 0;
                }
//                error(ans.size(),(char)i, check);
                if(check){
                    ans += i;
                    done.push_back(ara[i][0]);
                    sort(done.begin(), done.end());
                    ara[i].clear();
                    notpos.clear();
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}
