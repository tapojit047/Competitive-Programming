#include<bits/stdc++.h>
using namespace std;
struct X
{
    int p;
    int q;
};
struct compare
{
    bool operator()(const X & a, const X & b)
    {
        return a.p>b.p;
    }
};

int main()
{

    priority_queue<X,vector<X>,compare> pq;
    X d;
    d.p = 3; d.q = 1000;
    pq.push(d);
    d.p = 1; d.q = 500;
    pq.push(d);
    d.p = 2; d.q = 200;
    pq.push(d);

    while(!pq.empty())
    {
        d = pq.top();
        pq.pop();
        cout<<d.p<<" "<<d.q<<endl;;
    }

    return 0;
}
