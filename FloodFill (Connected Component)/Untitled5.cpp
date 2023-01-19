#include<bits/stdc++.h>
using namespace std;
string grid[101];

int N, M;

bool visited[101][101];
int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, 1};

int c = 0;

bool valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void floodfill(int x, int y)
{

    //cout<<x<<' '<<y<<endl;
    visited[x][y] = 1;
    grid[x][y] = '+';

    for(int i = 0; i < 8; i++){
        int p = x+dx[i];
        int q = y+dy[i];
        if(!valid(p, q)){
            continue;
        }
        if(!visited[p][q] && grid[p][q] == '.'){
            floodfill(p, q);
        }
    }
}
int main()
{
    scanf("%d%d", &N, &M);
    getchar();
    for(int i = 0; i < N; i++){
        getline(cin, grid[i]);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                c++;
                floodfill(i, j);
            }
        }
    }

    cout<<c<<endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
