#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll zero, one;
bool func(char a, char b)
{
    return a > b;
}
void decitobin(ll n)
{
    ll m;
    while(n != 0){
        m = n % 2;
        str += ('0' + m);
        if(m == 0){
            zero++;
        }
        else{
            one++;
        }
        n = n/2;
    }
}
ll bintodeci()
{
    ll n = 0;
    double p;
    ll x = str.size();
    x = 0;
    for(int i = 0; i < str.size(); i++){
        p = pow(2, x);
        n = n + p*(str[i] - '0');
        x++;
    }
    return n;
}
int main()
{
    ll t, n, T, l;
    scanf("%lld", &T);
    for(t = 1; t <= T; t++){
        zero = 0;
        one = 0;
        str.clear();
        scanf("%lld", &n);
        //n = t;
        decitobin(n);
      //  cout<<1<<endl;
       // cout<<str<<' '<<zero<<' '<<one<<endl;
       ll c = 0;
       for(int i = 0; i < str.size(); i++){
            if(str[i] == '0'){
                c++;
            }
            else{
                break;
            }
       }
       if(c == zero && one != 1){
            l = str.size();
            str += str[l-1];
            str[l-1] = '0';
            sort(str.begin(), str.end()-2, func);
       }
       else if(zero == 0 || (one == 1 && zero > 0)){
           // cout<<"HERE2"<<endl;
            l = str.size();
            str += str[l-1];
            str[l-1] = '0';
        }
        else if(zero > 0){
            //cout<<"HERE"<<endl;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == '1' && str[i+1] == '0'){
                   // cout<<2<<endl;
                    swap(str[i], str[i+1]);
                   // cout<<2<<endl;
                    sort(str.begin(), str.begin()+i, func);
                    break;
                }
            }
        }
       // cout<<1<<endl;
       //cout<<str<<endl;
        printf("Case %lld: %lld\n", t, bintodeci());
    }
}
