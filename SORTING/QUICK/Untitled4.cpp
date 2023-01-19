#include<bits/stdc++.h>
using namespace std;
int ara[105];
int partitionn(int l, int r)
{
    int piv = ara[l];
    int i = l, j = r;
    while(i < j){
        do{
            i++;
        }while(ara[i] <= piv);

        do{
            j--;
        }while(ara[j] > piv);

        if(i < j){
            swap(ara[i], ara[j]);
        }
    }
    swap(ara[l], ara[j]);
    return j;
}
void quicksort(int l, int r)
{
    if(l < r){
        int j = partitionn(l, r);
        quicksort(l, j);
        quicksort(j+1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }
    n++;
    quicksort(0, n-1);
    for(int i = 0; i < n-1; i++){
        cout<<ara[i]<<' ';
    }
    cout<<endl;
}
