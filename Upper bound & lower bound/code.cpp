// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  int low=lower_bound (v.begin(), v.end(), 20) -  v.begin(); //          ^
  int up= upper_bound (v.begin(), v.end(), 20) -  v.begin(); //
 int up = upper_bound (ara, ara+n, 20) -  ara;
 int low = lower_bound(ara, ara+n, 20) - ara;                    ^

  cout << "lower_bound at position " << (low) << '\n';
  cout << "upper_bound at position " << (up) << '\n';

  return 0;
}