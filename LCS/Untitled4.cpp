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
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

#define        MX        3005
string str1, str2;

int dp[MX][MX];

string LCS()
{
    int n = str1.size(), m = str2.size();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

        if(str1[i - 1] == str2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    string ans;
    while(dp[i][j]){
        if(dp[i][j] == dp[i-1][j]) i--;

        else if(dp[i][j] == dp[i][j-1]) j--;

        else{
            ans += str1[i-1];
            i--, j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cin>>str1>>str2;

    cout<<LCS()<<endl;
}
