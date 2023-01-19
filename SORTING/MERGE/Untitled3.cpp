#include<bits/stdc++.h>
using namespace std;
int n, ara[105];

void mergee(int l, int r, int m)
{
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = ara[l+i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = ara[m+i+1];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            ara[k] = L[i];
            i++;
        }
        else if(L[i] > R[j]){
            ara[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        ara[k] = L[i];
        k++, i++;
    }
    while(j < n2){
        ara[k] = R[j];
        k++, j++;
    }
}

void mergesort(int l, int r)
{
    if(l < r){
        int m = l+(r-l)/2;
        mergesort(l, m);
        mergesort(m+1, r);

        mergee(l, r, m);
    }
}
int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    mergesort(0, n-1);
    for(int i = 0; i < n; i++){
        cout<<ara[i]<<' ';
    }
    cout<<endl;
}
