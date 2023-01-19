#include<bits/stdc++.h>
using namespace std;
#define gcd(a, b) __gcd(a, b)
#define mp make_pair
#define pb push_back
#define RESET(a, b) memset(a, b, sizeof(a))

int countt(int n)
{
    int c = 0;
    while(n){
        n /= 5;
        c += n;
    }
    return c;
}
int main()
{
    int k;
    scanf("%d", &k);
    int b = 0;
    int e = 1e9;
    while(b <= e){
        int mid = (b+e)/2;
        int x = countt(mid);
        if(x < k){
            b = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    vector <int> ans;
    while(countt(b) == k){
        ans.pb(b);
        b++;
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
}

