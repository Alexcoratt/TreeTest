#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>

template <typename T>
class BinNode;

template <typename T>
class BinTree {
public:
    using value_t = T;
    using size_t = std::size_t;
    using node_t = BinNode<T>;

    // basic methods
        BinTree(BinTree::size_t nodeCount = 0UL);

        BinTree(const BinTree &);
        BinTree(BinTree &&);

        BinTree &operator=(const BinTree &);
        BinTree &operator=(BinTree &&);

        ~BinTree() = default;

        void swap(BinTree &);

    // setting
        void resize(BinTree::size_t);
        
        node_t &at(BinTree::size_t);
        node_t &operator[](BinTree::size_t);

        const node_t &at(BinTree::size_t) const;
        const node_t &operator[](BinTree::size_t) const;
};

template <typename T>
class BinNode {
public:
    using value_t = T;
    using tree_t = BinTree<T>;
    using size_t = typename tree_t::size_t;

    // basic methods
        BinNode(tree_t *, value_t);
        
        BinNode(const BinNode &) = delete;
        BinNode(BinNode &&) = delete;

        BinNode &operator=(const BinNode &) = delete;
        BinNode &operator=(BinNode &&) = delete;

        ~BinNode() = default;

        void swap(BinNode &);

    // setting
        void setLeft(BinNode::size_t);
        void setRight(BinNode::size_t);

    // public fields
        value_t value;

    private:
    BinNode::size_t left;
    BinNode::size_t right;
    tree_t *_tree;
};

#endif