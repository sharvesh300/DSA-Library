#ifndef BST_HPP
#define BST_HPP

#include <iostream> // For PrintTree

/*
 * The tree is meant to be used as the underlying representation
 * for dictionary implementation. Each node therefore holds 
 * a (key,value) pair.
 */
template<class K, class V>
struct TreeNode {
    K key;
    V value;
    TreeNode *left, *right;

    TreeNode(K key, V value, TreeNode *left, TreeNode *right)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

template<class K, class V>
class BST {
private:
    TreeNode<K,V> *root;

    bool remove(K key, TreeNode<K,V> *&node); // auxiliary function for deleteKey
    void PrintTree(TreeNode<K,V> *t);
    void DeleteTree(TreeNode<K,V> *t); // auxiliary function for ~BST()
    TreeNode<K,V> insertRec(K key, V value, TreeNode<K,V> *&t);

public:
    BST();
    void insert(K key, V value);
    void insertRec(K key, V value); // Calls the corresponding auxiliary fn
    bool search(K key, V &value); // Search for a key and store the corresponding value
    bool deleteKey(K key); // delete the corresponding (key,value) pair from tree
    void PrintTree(); // calls auxiliary function to recursively print the tree in order
    ~BST(); // destructor
};

template<class K, class V>
void BST<K, V>::insertRec(K key, V value) {
    root = insertRec(key, value,root);
}


template<class K, class V>
TreeNode<K,V> BST<K, V>::insertRec(K key, V value, TreeNode<K, V> *&t) {
    if (t == nullptr) {
        return new TreeNode<K,V>(key, value);
    }
    if (key < t->key) {
        t->left = insertRec(key, value, t->left);
    }
    else if (key > t->key) {
        t->right = insertRec(key, value, t->right);
    }
    else {
        t->value = value;
    }
    return t;
}


template<class K, class V>
BST<K,V>::BST()
{
    root = nullptr;
}

// Iterative insert implementation
template<class K, class V>
void BST<K,V>::insert(K key, V value)
{
    TreeNode<K, V>* newNode = new TreeNode<K, V>(key, value, nullptr, nullptr);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    TreeNode<K, V>* current = root;
    while (true) {
        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            current = current->left;
        } else if (key > current->key) {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            current = current->right;
        } else { // Key already exists, update the value
            current->value = value;
            delete newNode; // Don't need the new node
            return;
        }
    }
}

template<class K, class V>
bool BST<K,V>::search(K key, V &value)
{
    TreeNode<K,V> *current = root;
    while(current != nullptr)
    {
        if(key < current->key)
        {
            current = current->left;
        }
        else if (key > current->key)
        {
            current = current->right;
        }
        else // Key found
        {
            value = current->value;
            return true;
        }
    }
    return false; // Key not found
}

// Public wrapper for PrintTree
template<class K, class V>
void BST<K,V>::PrintTree()
{
    PrintTree(root);
    std::cout << std::endl;
}

// Private recursive function to print tree in-order
template<class K, class V>
void BST<K,V>::PrintTree(TreeNode<K,V> *t)
{
    if (t == nullptr) {
        return;
    }
    PrintTree(t->left);
    std::cout << "(" << t->key << ": " << t->value << ") ";

    PrintTree(t->right);

}

// // Private recursive insert implementation
// template<class K, class V>
// void BST<K,V>::insertrec(K key, V value, TreeNode<K,V> *&t)
// {
//     if (t == nullptr)
//     {
//         t = new TreeNode<K,V>(key, value, nullptr, nullptr);
//     }
//     else if (key < t->key)
//     {
//         insertrec(key, value, t->left);
//     }
//     else if (key > t->key)
//     {
//         insertrec(key, value, t->right);
//     }
//     else // Key exists, update value
//     {
//         t->value = value;
//     }
// }

// Public wrapper for recursive insert

/*
 * the code for auxiliary function is retained here for study 
 */
template<class K, class V>
bool BST<K,V>::remove(K key, TreeNode<K,V> *&node)
{
    if(node == nullptr)
    {
        
        return false;
    }
    if(key < node->key)
        return remove(key, node->left);
    else if(key > node->key)
        return remove(key, node->right);
    else
    {
        
        if(node->right != nullptr && node->left != nullptr)
        {
            TreeNode<K,V> *successor = node->right;
            
            for(;successor->left != nullptr; successor=successor->left);
            node->key = successor->key; 
            node->value = successor->value; 
            return remove(successor->key, node->right); 
        }
        else
        {
            
            TreeNode<K,V> *oldNode = node;
            if(node->left == nullptr)
                node = node->right; 
            else
                node = node->left; 
            delete oldNode; 
            return true; 
        }
    }
}

template<class K, class V>
bool BST<K,V>::deleteKey(K key)
{
    return remove(key, root);
}

template<class K, class V>
void BST<K,V>::DeleteTree(TreeNode<K,V> *t)
{
    if (t != nullptr)
    {
        DeleteTree(t->left);
        DeleteTree(t->right);
        delete t;
    }
}

template<class K, class V>
BST<K,V>::~BST()
{
    DeleteTree(root);
}

#endif