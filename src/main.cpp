#include <iostream>
#include <stack>
#include <utility>

#include "bin_tree.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &, const BinTree<T> &);

int main(int argc, char **argv) {
    BinTree<int> tree;
    
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

    return 0;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree) {
    std::stack<std::pair<std::size_t, typename BinTree<T>::node_t>> nodes;
    auto root = tree.getRoot();
    if (root == BinTree<T>::EMPTY_NODE)
        return out;

    nodes.push({0UL, root});

    while (!nodes.empty()) {
        auto pair = nodes.top();
        nodes.pop();
        const auto depth = pair.first;
        const auto node = pair.second;
        if (node != BinTree<T>::EMPTY_NODE) {
            for (decltype(pair.first) i = 0UL; i < depth; ++i) out << "    ";
            out << tree.getValue(node) << '\n';
            nodes.push({depth + 1, tree.getRight(node)});
            nodes.push({depth + 1, tree.getLeft(node)});
        }
    }

    return out;
}