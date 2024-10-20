#ifndef BIN_TREE_HPP
#define BIN_TREE_HPP

#include <vector>
#include <stack>
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
        void removeNode(node_t);

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
    std::stack<node_t> _unbound;
};

// definitions
#define BTREE_TMPLT template <typename T>
#define BTREE BinTree<T>

// basic methods
    BTREE_TMPLT BTREE::BinTree(BinTree::size_t nodeCount) : _root(EMPTY_NODE), _nodes(nodeCount) {
        for (node_t i = 0; i < nodeCount; ++i) {
            _nodes[i].left = EMPTY_NODE;
            _nodes[i].right = EMPTY_NODE;
            _unbound.push(i);
        }
    }

    BTREE_TMPLT BTREE::BinTree(const BinTree &other) : _root(other._root), _nodes(other._nodes), _unbound(other._unbound) {}
    BTREE_TMPLT BTREE::BinTree(BinTree &&other) : _root(other._root), _nodes(std::move(other._nodes)), _unbound(std::move(other._unbound)) {}

    BTREE_TMPLT BTREE &BTREE::operator=(const BinTree &other) {
        _root = other._root;
        _nodes = other._nodes;
        _unbound = other._unbound;
        return *this;
    }

    BTREE_TMPLT BTREE &BTREE::operator=(BinTree &&other) {
        _root = other._root;
        _nodes = std::move(other._nodes);
        _unbound = std::move(other._unbound);
        return *this;
    }

    BTREE_TMPLT void BTREE::swap(BinTree &other) {
        std::swap(_root, other._root);
        _nodes.swap(other._nodes);
        _unbound.swap(other._unbound);
    }

// setting
    BTREE_TMPLT typename BTREE::node_t BTREE::createNode(value_t value, node_t left, node_t right) {
        auto res = EMPTY_NODE;

        if (!_unbound.empty()) {
            res = _unbound.top();
            _unbound.pop();
            _nodes[res] = {value, left, right};
        } else {
            _nodes.push_back({value, left, right});
            res = _nodes.size() - 1;
        }

        if (_root == EMPTY_NODE) _root = res;
        else if (_root == left || _root == right) _root = res;

        return res;
    }

    BTREE_TMPLT void BTREE::removeNode(node_t node) {
        std::stack<node_t> nodesToRemove;
        nodesToRemove.push(node);

        while (!nodesToRemove.empty()) {
            auto nd = nodesToRemove.top();
            nodesToRemove.pop();

            if (nd != EMPTY_NODE) {
                nodesToRemove.push(getRight(nd));
                nodesToRemove.push(getLeft(nd));
                _unbound.push(nd);
            }
        }

        if (node == _root)
            _root = EMPTY_NODE;
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

#undef BTREE_TMPLT
#undef BTREE

#endif