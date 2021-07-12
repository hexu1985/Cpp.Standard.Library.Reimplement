#include <iostream>
#include "set.hpp"
 
int main()
{
    mini_stl::set<char> s;
    std::cout << "Maximum size of a 'set' is " << s.max_size() << "\n";
}

/*
Possible output:

Maximum size of a 'set' is 576460752303423487
*/
