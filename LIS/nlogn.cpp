#include<bits/stdc++.h>
using namespace std;
vector <int> seq;
vector <int> idx;

int parent[100005];
int ara[100005];
int N = 0;

int bsearch(int val)
{
    int b = 0, e = seq.size()-1;

    while(b <= e){
        int mid = (b+e)/2;
        if(seq[mid] == val){
            return mid;
        }
        if(val > seq[mid]){
            b = b + 1;
        }
        else if(val < seq[mid]){
            e = e - 1;
        }
    }
    return b;
}
void LIS()
{
    seq.clear();
    idx.clear();
    for(int i = 0; i < N; i++){
        parent[i] = -1;
    }

    seq.push_back(ara[0]);
    idx.push_back(0);

    for(int i = 1; i < N; i++){
        if(ara[i] > ara[idx[idx.size()-1]]){
            parent[i] = idx[idx.size()-1];
            seq.push_back(ara[i]);
            idx.push_back(i);
        }
        else{
            int p = lower_bound(seq.begin(), seq.end(), ara[i])-seq.begin();
                seq[p] = ara[i];
                if(p>0)parent[i] = idx[p-1];
                idx[p] = i;
        }
    }
}
int main()
{
    //X:
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
    int temp;
    N = 0;

    while(cin>>temp){
        ara[N] = temp;
        N++;
    }

    LIS();

    int i = idx[idx.size()-1];

    vector <int> ans;

    while(i != -1){
        ans.push_back(ara[i]);
        i = parent[i];
    }

    printf("%d\n-\n", ans.size());

    for(int i = ans.size()-1; i >= 0; i--){
        cout<<ans[i]<<endl;
    }

    //goto X;
}
