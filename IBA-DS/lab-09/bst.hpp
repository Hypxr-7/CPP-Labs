#pragma once
#include <vector>
#include <stdexcept>
#include <queue>
#include <cassert>

template<typename Key, typename Value> 
class BST {
    struct Node {
        Key key;
        Value val;
        Node *left, *right;
        int count;
        Node(Key k, Value v, int c=1) : key{k}, val{v}, left{nullptr}, right{nullptr}, count{c} {  }
    };

    Node* root;

public:
    // public interface
    BST() : root{nullptr} {  }
    ~BST() { removeall(root); }

    Value get(const Key& key) {
        Node *x = root;
        while (x != nullptr) {
            if      (key < x->key) x = x->left;
            else if (x->key < key) x = x->right;
            else                  return x->val;
        }
        throw std::out_of_range("Key not found");
    }

    void put(const Key& key, const Value& val) {  
        root = put(root, key, val);  
    }

    Value& operator[](const Key& key) {
        if (root == nullptr)         
            root = new Node(key, Value());

        Node* x = root;
        while(true) {
            if (key < x->key) {
                if(x->left==nullptr) x->left = new Node(key, Value());
                x = x->left;
            }
            else if (x->key < key) {
                if(x->right==nullptr) x->right = new Node(key, Value());
                x = x->right;       
            }
            else return x->val;
        }
    }    

    Key min() {  
        if (root == nullptr) throw std::out_of_range("called min() with empty symbol table");
        Node* x = root;
        while (x->left != nullptr) x = x->left;
        return x->key;
    }

    Key floor(const Key& key) {  
        Node* x = floor(root, key);
        if (x == nullptr) throw std::out_of_range("argument to floor() is too small");
        return x->key;
    }

    int size() {  
        return size(root);  
    }

    int rank(Key key) {  
        return rank(key, root);  
    } 

    Key select(int k) {   
        if (k < 0 || k >= size()) 
            throw std::out_of_range("called select() with invalid argument"); 

        Node* x = select(root, k);
        return x->key;
    } 

    std::vector<Key> keys() { 
        std::vector<Key> q; 
        inorder(root, q); 
        return q;
    }

    void removeMin() {  
        if(root == nullptr) throw std::out_of_range("Symbol table underflow");
        root = removeMin(root);  
    }

    void remove(const Key& key) {  
        root = remove(root, key);  
    }

private:
    // private helper functions

    Node* put(Node* x, const Key& key, const Value& val)  {
        if (x == nullptr) return new Node(key, val, 1);
        
        if (key < x->key)  
            x->left  = put(x->left,  key, val);
        else if (x->key < key)  
            x->right = put(x->right, key, val);
        else                    
            x->val = val;
        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }

    Node* floor(Node* x, const Key& key) {  
        if (x == nullptr) return nullptr;
        if (key == x->key) return x;

        if (key < x->key)  
            return floor(x->left, key);

        Node* t = floor(x->right, key);
        if (t != nullptr) return t;
        else              return x;
    } 

    int size(Node* x) {
        if (x == nullptr) return 0;
        return x->count;
    }

    int rank(const Key& key, Node* x) { 
        if (x == nullptr) return 0; 
        
        if (key < x->key) 
            return rank(key, x->left); 
        else if (key > x->key) 
            return 1 + size(x->left) + rank(key, x->right); 
        else
            return size(x->left); 
    } 

    Node* select(Node* x, int k) {
        if (x == nullptr) return nullptr; 

        int t = size(x->left); 
        if (t > k)
            return select(x->left,  k);
        else if (t < k)
            return select(x->right, k-t-1);
        else
            return x; 
    } 

    void inorder(Node* x, std::vector<Key>& q) { 
        if (x == nullptr) return; 
        inorder(x->left, q); 
        q.push_back(x->key); 
        inorder(x->right, q); 
    } 

    Node* removeMin(Node* x) {
        if (x->left == nullptr) {
            Node* right = x->right;
            delete x;
            return right;
        }
        x->left  = removeMin(x->left);
        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }

    Node* remove(Node* x, const Key& key) {
        if (x == nullptr) return nullptr;

        if (key < x->key) 
            x->left  = remove(x->left,  key);
        else if (x->key < key) 
            x->right = remove(x->right, key);
        else { 
            if (x->right == nullptr) return x->left;
            if (x->left  == nullptr) return x->right;

            Node* t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        } 
        x->count = size(x->left) + size(x->right) + 1;
        return x;
    } 

    void removeall(Node* x) {
        if (x == nullptr) return;
        removeall(x->left);
        removeall(x->right);
        delete x;
    }

/************************************************************************************
 * Question 1
 ************************************************************************************/

public:
    int height_recursive() const {
        return height_recursive(root);
    }

private:
    int height_recursive(Node* node) const {
        if (node == nullptr) return -1;
        return 1 + std::max(height_recursive(node->right), height_recursive(node->left));
    }

public:
    int height_iterative() const {
        if (root == nullptr) return -1;

        std::queue<Node*> q;
        q.push(root);
        int height = -1;

        while (!q.empty()) {
            int levelSize = q.size();
            height++;
            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }

        return height;
    }

    int size_iterative() const {
        if (root == nullptr) return 0;

        int count = 0;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            count++;

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

        return count;
    }

/************************************************************************************
 * Question 2
 ************************************************************************************/

public:
    bool isEmpty() { return size() == 0; }

    std::vector<Key> keys(const Key& lo, const Key& hi) const {
        std::vector<Key> list;
        keys(root, list, lo, hi);
        return std::move(list);
    }

private:
    void keys(Node* node, std::vector<Key>& list, const Key& lo, const Key& hi) const {
        if (node == nullptr) return;
        if (lo < node->key) keys(node->left, list, lo, hi);
        if (lo <= node->key && hi >= node->key) list.push_back(node->key);
        if (hi > node->key) keys(node->right, list, lo, hi);
    }

public:
    Key max() {
        if (isEmpty()) throw std::runtime_error("calls max() with empty symbol table");
        return max(root)->key;
    }

private:
    Node* max(Node* node) {
        return node->right != nullptr ? max(node->right) : node;
    }

public:
    Key ceiling(const Key& key) {
        Node* node = ceiling(root, key);
        if (node == nullptr) throw std::runtime_error("argument to ceiling() is too large");
        return node->key;
    }

private:
    Node* ceiling(Node* node, const Key& key) {
        if (node == nullptr) return nullptr;
        if (key == node->key) return node;
        if (key > node->key) return ceiling(node->right, key);
        Node* temp = ceiling(node->left, key);
        return temp != nullptr ? temp : node; 
    }

public:
    void deleteMax() {
        if (isEmpty()) throw std::runtime_error("Symbol table underflow");
        root = deleteMax(root);
    }

private:
    Node* deleteMax(Node* node) {
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        node->right = deleteMax(node->right);
        node->count = size(node->left) + size(node->right) + 1;
        return node;
    }
/************************************************************************************
 * Question 3
 ************************************************************************************/
public:
    std::vector<Key> levelOrder() const {
            if (root == nullptr) return std::vector<Key>{};
            std::vector<Key> keys;
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* node = q.front();
                q.pop();
                if (node != nullptr) {
                    keys.push_back(node->key);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            return keys;
        }
/************************************************************************************
 * Question 4
 ************************************************************************************/
private:
    bool isBST(Node* node) {
        return isBST(node, Key{}, Key{});
    }

    bool isBST(Node* node, const Key& min, const Key& max) {
        if (node == nullptr) return true;
        if (min != Key{} && node->key <= min) return false;
        if (max != Key{} && node->key >= max) return false;
        return isBST(node->left, min, node->key) && isBST(node->right, node->key, max); 
    }

public:
    void test() {
        assert(isBST(root));
    }
/************************************************************************************
 * Question 5
 ************************************************************************************/
public:
    bool isRankConsistent() {
        for (int i = 0; i < size(); ++i) 
            if (i != rank(select(i))) return false;

        for (const Key& key : keys())
            if (key != select(rank(key))) return false;
            
        return true;
    }

};

