#include<bits/stdc++.h>
using namespace std;
bool palin(int N)
{
    int temp = N;
    int c = 0, a, rev = 0;
    while(N){
        a = N % 10;
        N /= 10;
        rev *= 10;
        rev = rev + a;
    }
    return temp == rev;
}
int main()
{
    int T;
    int N, temp, rev;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &N);

        palin(N) ? printf("Case %d: Yes\n", t) : printf("Case %d: No\n", t);
    }
}
