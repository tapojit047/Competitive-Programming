#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define lo %I64d
#define INF -1000000
#define MAX 99901

int main()
{
    ll T, a, b, x;
    string str;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>str>>b;
        //cout<<str<<endl<<b<<endl;
        if(b < 0){
            b *= (-1);
        }
        ll i;
        if(str[0] == '-'){
            i = 1;
        }
        else{
            i = 0;
        }
        ll l = str.size();
        ll p = l, num = 0;
        for(; i < l; i++){
            num *= 10;
            num = num + (str[i] - '0');
            if(num >= b){
                a = num / b;
                num = num - (b*a);
            }
        }
        if(num == 0){
            printf("Case %d: divisible\n", t);
        }
        else{
            printf("Case %d: not divisible\n", t);
        }
    }
}
