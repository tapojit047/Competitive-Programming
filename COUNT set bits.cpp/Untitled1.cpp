#include<bits/stdc++.h>
using namespace std;
#define MX 2147483648
typedef long long ll;
list <ll> li;
list <ll>:: iterator it;
ll bitwiseOR(int n)
{
    ll maxi = 0, OR;
    for(it = li.begin(); it != li.end(); it++){
      //  cout<<*it<<endl;
        //cout<<OR<<endl;
        if((*it | n) > maxi){
            maxi = (*it | n);
        }
    }
    return maxi;
}
int main()
{
    ll i, q, x;
    char ch;
    li.push_back(0);
    scanf("%I64d", &q);
    for(i = 1; i <= q; i++){
        getchar();
        scanf("%c", &ch);
        if(ch == '+'){
            scanf("%I64d", &x);
            li.push_back(x);
            //cout<<1<<endl;
        }
        else if(ch == '-'){
            scanf("%I64d", &x);
            it = find(li.begin(), li.end(), x);
            li.erase(it);
            for(it = li.begin(); it != li.end(); it++){
                cout<<*it<<' ';
            }
            cout<<endl;
        }
        else if(ch == '?'){
            scanf("%I64d", &x);
            printf("%lld\n", bitwiseOR(x));
        }
    }
}
