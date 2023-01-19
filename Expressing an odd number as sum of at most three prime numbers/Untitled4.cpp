#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Function to check if a number is prime or not.
bool isPrime(ll x)
{
    if (x == 0 || x == 1)
        return false;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

// Prints at most three prime numbers whose
// sum is n.
void findPrimes(ll n)
{
    if (isPrime(n)){
        // CASE-I
        cout<<1<<endl;
        cout << n << endl;
    }
    else if (isPrime(n - 2)){
        // CASE-II
        cout<<2<<endl;
        cout << 2 << " " << n - 2 << endl;
    }
    else // CASE-III
    {
        cout<<3<<endl;
        cout << 3 << " ";
        n = n - 3;
        for (ll i = 0; i < n; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << (n - i);
                break;
            }
        }
    }
}

// Driver code
int main()
{
    ll n;
    cin>>n;
    ///works upto 10^9
    findPrimes(n);
    return 0;
}
