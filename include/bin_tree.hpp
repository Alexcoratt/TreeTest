#ifndef BIN_TREE_HPP
#define BIN_TREE_HPP

#include <vector>
#include <climits>
#include <cstddef>

template <typename T>
class BinTree {
public:
    using value_t = T;
    using size_t = std::size_t;
    using node_t = std::size_t;

    static constexpr BinTree::node_t EMPTY_NODE = ULONG_MAX;

private:
    // auxillary structure
    struct BinNode {
        value_t value;
        node_t left;
        node_t right;
    };

public:
    // basic methods
        BinTree(BinTree::size_t nodeCount = 0UL);

        BinTree(const BinTree &);
        BinTree(BinTree &&);

        BinTree &operator=(const BinTree &);
        BinTree &operator=(BinTree &&);

        ~BinTree() = default;

        void swap(BinTree &);

    // setting
        node_t createNode(value_t, node_t left = EMPTY_NODE, node_t right = EMPTY_NODE);

        void setValue(node_t, value_t);
        void setLeft(node_t nodeToReset, node_t newLeft);
        void setRight(node_t nodeToReset, node_t newRight);

    // getting
        node_t getRoot() const;

        value_t getValue(node_t) const;
        node_t getLeft(node_t) const;
        node_t getRight(node_t) const;

private:
    node_t _root;
    std::vector<BinNode> _nodes;
};

// definitions
#define BTREE_TMPLT template <typename T>
#define BTREE BinTree<T>

// basic methods
    BTREE_TMPLT BTREE::BinTree(BinTree::size_t nodeCount) : _root(EMPTY_NODE), _nodes(nodeCount) {}

    BTREE_TMPLT BTREE::BinTree(const BinTree &other) : _root(other._root), _nodes(other._nodes) {}
    BTREE_TMPLT BTREE::BinTree(BinTree &&other) : _root(other._root), _nodes(std::move(other._nodes)) {}

    BTREE_TMPLT BTREE &BTREE::operator=(const BinTree &other) {
        _root = other._root;
        _nodes = other._nodes;
        return *this;
    }

    BTREE_TMPLT BTREE &BTREE::operator=(BinTree &&other) {
        _root = other._root;
        _nodes = std::move(other._nodes);
        return *this;
    }

// setting
    BTREE_TMPLT typename BTREE::node_t BTREE::createNode(value_t value, node_t left, node_t right) {
        _nodes.push_back({value, left, right});
        node_t res = _nodes.size() - 1;

        if (_root == EMPTY_NODE) _root = res;
        else if (_root == left || _root == right) _root = res;

        return res;
    }

    BTREE_TMPLT void BTREE::setValue(node_t node, value_t value) { _nodes.at(node).value = value; }

    BTREE_TMPLT void BTREE::setLeft(node_t node, node_t left) {
        if (_root == left) _root = node;
        _nodes.at(node).left = left;
    }

    BTREE_TMPLT void BTREE::setRight(node_t node, node_t right) {
        if (_root == right) _root = node;
        _nodes.at(node).right = right;
    }

// getting
    BTREE_TMPLT typename BTREE::node_t BTREE::getRoot() const { return _root; }

    BTREE_TMPLT typename BTREE::value_t BTREE::getValue(node_t node) const { return _nodes.at(node).value; }
    BTREE_TMPLT typename BTREE::node_t BTREE::getLeft(node_t node) const { return _nodes.at(node).left; }
    BTREE_TMPLT typename BTREE::node_t BTREE::getRight(node_t node) const { return _nodes.at(node).right; }

#endif