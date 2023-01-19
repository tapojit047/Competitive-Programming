#include<bits/stdc++.h>
using namespace std;
string str1, str2;
int ara[10005][10005];
int LCS()
{
    int n1 = str1.size(), n2 = str2.size();

    for(int i = 1; i < n1; i++){
        for(int j = 1; j < n2; j++){
            if(str1[i] == str2[j]){
                ara[i][j] = (ara[i-1][j-1]+1);
            }
            else{
                ara[i][j] = max(ara[i-1][j], ara[i][j-1]);
            }
        }
    }
    return ara[n1-1][n2-1];
}
int main()
{
    str1 += '0';
    str2 += '0';
    string temp;
    cin>>temp;
    str1 += temp;
    cin>>temp;
    str2 += temp;
    cout<<LCS()<<endl;
}
