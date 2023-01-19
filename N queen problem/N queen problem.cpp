#include<bits/stdc++.h>
using namespace std;

int N = 8;
int column[100], diagonal11[100], diagonal12[100], ara[100][100], queen[100];

void nqueen(int att)
{
    if(att == N+1){
        for(int i = 1; i <= N; i++){
            cout<<i<<' '<<queen[i]<<endl;
        }
        cout<<endl;
        return;
    }

    for(int i = 1; i <= N; i++){
        if(column[i] || diagonal11[att+i] || diagonal12[N+att-i]){
            continue;
        }
        column[i] = diagonal11[att+i] = diagonal12[N+att-i] = 1;
        queen[att] = i;
        nqueen(att+1);
        column[i] = diagonal11[att+i] = diagonal12[N+att-i] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++){
        int N;
        scanf("%d", &N);
      /*  for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                scanf("%d", &ara[i][j]);
            }
        } */
        nqueen(1);
    }
}
