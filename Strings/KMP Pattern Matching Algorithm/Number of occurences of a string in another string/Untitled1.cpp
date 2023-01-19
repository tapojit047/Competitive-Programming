#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)

#define        MX        200005

vector <int> createlps(string pattern)
{
    int index = 0;
    vector <int> lps(pattern.size());
    for(int i = 1; i < pattern.size();){
        if(pattern[i] == pattern[index]){
            lps[i] = index+1;
            i++, index++;
        }
        else{
            if(index != 0){
                index = lps[index-1];
            }
            else{
                i++;
                lps[i] = 0;
            }
        }
    }
    return lps;
}

bool kmp(string text, string pattern)
{
    vector <int> lps = createlps(pattern);
    ///i --> text, j --> pattern
    bool flag = 0;
    int i = 0, j = 0;
    while(i < text.size()){
        if(text[i] == pattern[j]){
            i++, j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j == pattern.size()){
            cout<<i-pattern.size()<<endl;
            flag = 1;
            j = lps[j-1];
        }
    }
    if(!flag) cout<<"NOT FOUND"<<endl;
}
int main()
{
    optimize
    string pattern, text;
    cin>>text>>pattern;
    kmp(text, pattern);
}
