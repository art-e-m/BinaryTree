#include <iostream>
#include "tree.hpp"

int main(int argc, const char * argv[]) {
    binary_tree<int> t;
    t.add(11);
    t.add(12);
    t.add(9);
    t.add(1);
    
    t.show();
    return 0;
}
