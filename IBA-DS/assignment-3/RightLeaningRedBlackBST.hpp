#pragma once

#include <cassert>
#include <iostream>
#include <queue>
#include <stdexcept>

template <typename Key, typename Value>
class RightLeaningRedBlackBST {
private:
    static const bool RED = true;
    static const bool BLACK = false;

    class Node {
    public:
        Key key;
        Value value;
        bool color;
        int size;
        Node* left;
        Node* right;

        Node(const Key& key, const Value& value, const bool color, const int size) : key(key),
                                                                                     value(value),
                                                                                     color(color),
                                                                                     size(size),
                                                                                     left(nullptr),
                                                                                     right(nullptr) {}
    };

    Node* root;

public:
    RightLeaningRedBlackBST() : root(nullptr) {}

    ~RightLeaningRedBlackBST() { clear(root); }

    void clear() {
        clear(root);
    }

private:
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    /*****************************************************************
     * Helper Methods
     *****************************************************************/

private:
    bool isRed(const Node* node) const {
        if (node == nullptr) return false;
        return node->color == RED;
    }

public:
    bool isEmpty() const { return root == nullptr; }

public:
    int size() const {
        return size(root);
    }

private:
    int size(const Node* node) const {
        if (node == nullptr) return 0;
        return node->size;
    }

    /*****************************************************************
     * BST Search
     *****************************************************************/
public:
    Value get(const Key& key) const {
        if (isEmpty()) throw std::runtime_error("Empty BST");
        return get(root, key);
    }

private:
    Value get(Node* node, const Key& key) const {
        while (node != nullptr) {
            if (key < node->key)
                node = node->left;
            else if (key > node->key)
                node = node->right;
            else
                return node->value;
        }
        throw std::out_of_range("Key not in BST");
    }

public:
    bool contains(const Key& key) const {
        try {
            get(key);
        } catch (...) {
            return false;
        }
        return true;
    }

private:
public:
    Value findMin() const {
        if (isEmpty()) throw std::runtime_error("Empty BST");
        return findMin(root);
    }

private:
    Value findMin(Node* node) const {
        while (node->left != nullptr)
            node = node->left;
        return node->value;
    }

public:
    Value findMax() const {
        if (isEmpty()) throw std::runtime_error("Empty BST");
        return findMax(root);
    }

private:
    Value findMax(Node* node) const {
        while (node->right != nullptr)
            node = node->right;
        return node->value;
    }

    /*****************************************************************
     * Right-leaning Red-Black Insertion
     *****************************************************************/
public:
    void put(const Key& key, const Value& value) {
        root = put(root, key, value);
        root->color = BLACK;

        // assert(check());
    }

private:
    Node* put(Node* node, const Key& key, const Value& val) {
        if (node == nullptr) return new Node(key, val, RED, 1);

        if (key < node->key)
            node->left = put(node->left, key, val);
        else if (key > node->key)
            node->right = put(node->right, key, val);
        else
            node->value = val;

        if (isRed(node->left) && !isRed(node->right)) node = rotateRight(node);
        if (isRed(node->right) && isRed(node->right->right)) node = rotateLeft(node);
        if (isRed(node->left) && isRed(node->right)) flipColors(node);

        node->size = size(node->left) + size(node->right) + 1;
        return node;
    }

    /*****************************************************************
     * Right-leaning Red-Black Deletion
     ******************************************************************/
public:
    void remove(const Key& key) {
        if (!isRed(root->left) && !isRed(root->right))
            root->color = RED;
        root = remove(root, key);
        if (!isEmpty())
            root->color = BLACK;
        else
            root = nullptr;

        // assert(check());
    }

private:
    Node* remove(Node* node, const Key& key) {
        if (key > node->key) {
            if (!isRed(node->right) && !isRed(node->right->right))
                node = moveRedRight(node);
            node->right = remove(node->right, key);
        } else {
            if (isRed(node->right)) node = rotateLeft(node);
            if (key == node->key && node->left == nullptr) {
                delete node;
                return nullptr;
            }
            if (!isRed(node->left) && !isRed(node->left->right))
                node = moveRedLeft(node);
            if (key == node->key) {
                Node* temp = max(node->left);
                node->key = temp->key;
                node->value = temp->value;
                node->left = removeMax(node->left);
            } else {
                node->left = remove(node->left, key);
            }
        }
        return balance(node);
    }

    Node* min(Node* node) const {
        if (node->left == nullptr)
            return node;
        else
            return min(node->left);
    }

    Node* max(Node* node) const {
        if (node->right == nullptr)
            return node;
        else
            return max(node->right);
    }

    Node* removeMax(Node* node) {
        if (node->right == nullptr) {
            delete node;
            return nullptr;
        }
        if (!isRed(node->right) && !isRed(node->right->right))
            node = moveRedRight(node);

        node->right = removeMax(node->right);

        return balance(node);
    }

    /*****************************************************************
     * Red-Black Tree Helper Methods
     ******************************************************************/
private:
    Node* rotateLeft(Node* node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        temp->color = node->color;
        node->color = RED;
        temp->size = node->size;
        node->size = size(node->left) + size(node->right) + 1;
        return temp;
    }

    Node* rotateRight(Node* node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        temp->color = node->color;
        node->color = RED;
        temp->size = node->size;
        node->size = size(node->left) + size(node->right) + 1;
        return temp;
    }

    void flipColors(Node* node) {
        node->color = !node->color;
        node->left->color = !node->left->color;
        node->right->color = !node->right->color;
    }

    Node* balance(Node* node) {
        if (isRed(node->left) && !isRed(node->right))
            node = rotateRight(node);
        if (isRed(node->right) && isRed(node->right->right))
            node = rotateLeft(node);
        if (isRed(node->right) && isRed(node->left))
            flipColors(node);

        node->size = size(node->left) + size(node->right) + 1;
        return node;
    }

    Node* moveRedLeft(Node* node) {
        flipColors(node);
        if (isRed(node->right->right)) {
            node = rotateLeft(node);
            flipColors(node);
        }
        return node;
    }

    Node* moveRedRight(Node* node) {
        flipColors(node);
        if (isRed(node->left->right)) {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
            flipColors(node);
        }
        return node;
    }

    /*****************************************************************
     * Utility Methods
     ******************************************************************/
public:
    int height() const {
        return height(root);
    }

private:
    int height(Node* node) const {
        if (node == nullptr) return -1;
        return 1 + std::max(height(node->left), height(node->right));
    }

public:
    Key select(const int rank) const {
        if (rank < 0 || rank >= size()) throw std::invalid_argument("argument to select() is invalid");
        return select(root, rank)->key;
    }

private:
    Node* select(Node* node, const int rank) const {
        if (node == nullptr) return nullptr;
        int leftSize = size(node->left);
        if (leftSize > rank)
            return select(node->left, rank);
        else if (leftSize < rank)
            return select(node->right, rank - leftSize - 1);
        else
            return node;
    }

public:
    int rank(const Key& key) const {
        return rank(root, key);
    }

private:
    int rank(const Node* node, const Key& key) const {
        if (node == nullptr) return 0;
        if (key < node->key)
            return rank(node->left, key);
        else if (key > node->key)
            return 1 + size(node->left) + rank(node->right, key);
        else
            return size(node->left);
    }

public:
    void printRange(const Key& lo, const Key& hi) const {
        if (isEmpty()) return;
        printRange(root, lo, hi);
    }

private:
    void printRange(Node* node, const Key& lo, const Key& hi) const {
        if (node == nullptr) return;
        if (lo < node->key) printRange(node->left, lo, hi);
        if (lo <= node->key && hi >= node->key) std::cout << '(' << node->key << ", " << node->value << ") ";
        if (hi > node->key) printRange(node->right, lo, hi);
    }

public:
    std::vector<Key> keys() const {
        if (isEmpty()) return std::vector<Key>{};
        return std::move(keys(min(root)->key, max(root)->key));
    }

    std::vector<Key> keys(const Key& lo, const Key& hi) const {
        std::vector<Key> arr;
        keys(root, arr, lo, hi);
        return std::move(arr);
    }

private:
    void keys(const Node* node, std::vector<Key>& arr, const Key& lo, const Key& hi) const {
        if (node == nullptr) return;
        if (lo < node->key) keys(node->left, arr, lo, hi);
        if (lo <= node->key && hi >= node->key) arr.push_back(node->key);
        if (hi > node->key) keys(node->right, arr, lo, hi);
    }

    /*****************************************************************
     * Traversal
     ******************************************************************/
public:
    void inorderTraversal() const {
        inorderTraversal(root);
    }

private:
    void inorderTraversal(Node* node) const {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        std::cout << '(' << node->key << ", " << node->value << ") ";
        inorderTraversal(node->right);
    }

public:
    void preorderTraversal() const {
        preorderTraversal(root);
    }

private:
    void preorderTraversal(Node* node) const {
        if (node == nullptr) return;

        std::cout << '(' << node->key << ", " << node->value << ") ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

public:
    void postorderTraversal() const {
        postorderTraversal(root);
    }

private:
    void postorderTraversal(Node* node) const {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << '(' << node->key << ", " << node->value << ") ";
    }

public:
    void levelorderTraversal() const {
        levelorderTraversal(root);
    }

private:
    void levelorderTraversal(Node* node) const {
        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            std::cout << '(' << temp->key << ", " << temp->value << ") ";
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }

    /*******************************************************************
     * Check integrity of red-black tree data structure
     * *****************************************************************/
private:
    bool check() const {
        if (!isBST()) std::cerr << "Not in symmetric order\n";
        if (!isSizeConsistent()) std::cerr << "Subtree counts not consistent\n";
        if (!isRankConsistent()) std::cerr << "Ranks not consistent\n";
        if (!is23()) std::cerr << "Not a 2-3 tree\n";
        if (!isBalanced()) std::cerr << "Not balanced\n";

        return isBST() && isSizeConsistent() && isRankConsistent() && is23() && isBalanced();
    }

    bool isBST() const {
        return isBST(root, Key{}, Key{});
    }

    bool isBST(Node* node, const Key& min, const Key& max) const {
        if (node == nullptr) return true;
        if (min != Key{} && node->key <= min) return false;
        if (max != Key{} && node->key >= max) return false;

        return isBST(node->left, min, node->key) && isBST(node->right, node->key, max);
    }

    bool isSizeConsistent() const {
        return isSizeConsistent(root);
    }

    bool isSizeConsistent(Node* node) const {
        if (node == nullptr) return true;
        if (node->size != size(node->left) + size(node->right) + 1) return false;
        return isSizeConsistent(node->left) && isSizeConsistent(node->right);
    }

    bool isRankConsistent() const {
        for (int i = 0; i < size(); ++i)
            if (i != rank(select(i))) return false;

        for (const auto& key : keys())
            if (key != select(rank(key))) return false;

        return true;
    }

    bool is23() const {
        return is23(root);
    }

    bool is23(Node* node) const {
        if (node == nullptr) return true;

        if (isRed(node->left)) return false;
        if (node != root && isRed(node) && isRed(node->right)) return false;
        return is23(node->left) && is23(node->right);
    }

    bool isBalanced() const {
        int black = 0;
        Node* node = root;
        while (node != nullptr) {
            if (!isRed(node)) ++black;
            node = node->left;
        }
        return isBalanced(root, black);
    }

    bool isBalanced(Node* node, int black) const {
        if (node == nullptr) return black == 0;
        if (!isRed(node)) --black;
        return isBalanced(node->left, black) && isBalanced(node->right, black);
    }

    /*******************************************************************
     * Unit Test
     * *****************************************************************/

public:
    static void testRightLeaningRedBlackBST() {
        RightLeaningRedBlackBST<int, std::string> bst;

        assert(bst.isEmpty());

        try {
            bst.get(1);
            assert(false);
        } catch (const std::runtime_error& e) {
            // empty on purpose
        } catch (...) {
            assert(false);
        }

        try {
            bst.findMin();
            assert(false);
        } catch (const std::runtime_error& e) {
            // empty on purpose
        } catch (...) {
            assert(false);
        }

        try {
            bst.findMax();
            assert(false);
        } catch (const std::runtime_error& e) {
            // empty on purpose
        } catch (...) {
            assert(false);
        }

        bst.put(1, "foo");
        bst.put(2, "bar");
        bst.put(3, "baz");
        bst.put(4, "qux");

        assert(!bst.isEmpty());

        assert(bst.get(1) == "foo");
        try {
            bst.get(-1);
            assert(false);
        } catch (const std::out_of_range& e) {
            // empty on purpose
        } catch (...) {
            assert(false);
        }

        assert(bst.findMin() == "foo");
        assert(bst.findMax() == "qux");

        assert(bst.height() == 2);

        bst.put(8, "xyz");
        bst.put(11, "abc");

        assert(bst.height() == 3);

        bst.printRange(1, 11);
        std::cout << '\n';
        bst.printRange(5, 11);
        std::cout << '\n';
        bst.printRange(1, 4);
        std::cout << '\n';
        bst.printRange(-1, -1);
        std::cout << '\n';

        /*
            The current tree diagram
                2
            1       4
                  3   8
                       11
        */

        bst.inorderTraversal();
        std::cout << '\n';
        bst.preorderTraversal();
        std::cout << '\n';
        bst.postorderTraversal();
        std::cout << '\n';
        bst.levelorderTraversal();
        std::cout << '\n';

        bst.remove(2);
        assert(!bst.contains(2));
    }
};