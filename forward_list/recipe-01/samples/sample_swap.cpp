// swap (forward_list overload)
#include <iostream>
#include "forward_list.hpp"

int main ()
{
  mini_stl::forward_list<int> first = {10, 20, 30};
  mini_stl::forward_list<int> second = {100, 200};
  mini_stl::forward_list<int>::iterator it;

  mini_stl::swap(first,second);

  std::cout << "first contains:";
  for (int& x: first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second contains:";
  for (int& x: second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}


/*
Output:
first contains: 100 200
second contains: 10 20 30
*/

