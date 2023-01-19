#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair <ll, ll>


vector <pii> pdiv;
void primedivisors(ll num)
{
    if(num%2 == 0){
        ll c = 0;
        while(num%2 == 0){
            num /= 2;
            c++;
        }
        pdiv.push_back({2, c});
    }
    //till sqrt(num)
    for(ll i = 3; i*i <= num; i+=2){
        if(num%i == 0){
            ll c = 0;
            while(num%i == 0){
                num /= i;
                c++;
            }
            pdiv.push_back({i, c});
        }
    }
    if(num > 2){
        pdiv.push_back({num, 1});
    }
}
int main()
{

}
