#include<bits/stdc++.h>
using namespace std;
#define pii  pair <int, int>
struct X
{
    int xx;
    int yy;
    int ll;
    int rr;
};
struct compare
{
    bool operator()(const X &a, const X &b)
    {

        return a.ll<b.ll && a.rr<b.rr;
    }
};
int main()
{
    priority_queue <X, vector <X>, compare> pq;

    ///For pair
    priority_queue <pii, vector < pii >, s<pii> > pairpq;
}
