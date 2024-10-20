#include <iostream>

#include "bin_tree.hpp"
#include "print_bin_tree.hpp"

int main(int argc, char **argv) {
    BinTree<int> tree(2);
    
    tree.createNode(
        3,
        tree.createNode(
            2,
            tree.createNode(5),
            tree.createNode(0)
        ), 
        tree.createNode(1)
    );

    std::cout << tree << '\n';

    tree.removeNode(tree.getRoot());

    std::cout << tree << '\n';

    return 0;
}