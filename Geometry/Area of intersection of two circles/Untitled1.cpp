#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

const ll MX = 2e5 + 105;

int Case = 1;

///https://reponroy.wordpress.com/2015/09/07/lightoj-1118/

int main()
{
//    optimize
    int t;
//    WRITE
    cin>>t;
    while(t--){
        double x1, y1, r1, x2, y2, r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        cout<<"Case "<<Case++<<": ";

        if(r1 < r2){
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }
        double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        if(d >= r1+r2) cout<<0<<endl; ///They don't touch
        else if(d > (r1-r2) && d < (r1+r2)){
            ///They intersect

            double theta1 = acos((r1*r1 + d*d - r2*r2)/(2*r1*d));
            double theta2 = acos((r2*r2 + d*d - r1*r1)/(2*r2*d));

            double area1 = (r1*r1*2*theta1*0.5)-(0.5*r1*r1*sin(2*theta1));
            double area2 = (r2*r2*2*theta2*0.5)-(0.5*r2*r2*sin(2*theta2));

//            error(d, theta1, theta2, area1, area2);

            printf("%.10f\n", area1+area2);
        }
        else{
            ///One is completely inside the other
            printf("%.10f\n", PI*r2*r2);
        }

    }
}
