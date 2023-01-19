///INSERTION

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[105], n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &ara[i]);
    }


    for(int i = 2; i <= n; i++){
        int j = i-1;
        int val = ara[i];

        while(j >= 1 && ara[j] > val){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = val;
    }

    for(int i = 1; i <= n; i++){
        cout<<ara[i]<<' ';
    }
}
