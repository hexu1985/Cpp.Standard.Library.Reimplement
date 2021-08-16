// enable_shared_from_this example
#include <iostream>
#include "shared_ptr.hpp"
#include "weak_ptr.hpp"
#include "enable_shared_from_this.hpp"

using mini_stl::shared_ptr;
using mini_stl::make_shared;
using mini_stl::enable_shared_from_this;

struct C : enable_shared_from_this<C> { };

int main () {
    shared_ptr<C> foo, bar;

    foo = make_shared<C>();

    bar = foo->shared_from_this();

    if (!foo.owner_before(bar) && !bar.owner_before(foo))
        std::cout << "foo and bar share ownership\n";

    return 0;
}



/*
Output:

foo and bar share ownership
*/

