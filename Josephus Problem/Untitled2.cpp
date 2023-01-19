
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
  if (n == 1)
    return 1;

    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    int x = (josephus(n - 1, k) + k) % n;
    return x;
}

// Driver Program to test above function
int main()
{
  int n;
  int k;
  cin>>n>>k;
  printf("The chosen place is %d", josephus(n, k));
  return 0;
}
