#ifndef  BST_Lazy_hpp
#define BST_Lazy_hpp

#include <iostream>

template <class K,class V>
class BinaryTreeLazy {

    public:
    BinaryTreeLazy() {
        this->root = nullptr;
    }



    private:
    struct TreeNode {
        K key;
        V value;
        TreeNode *left;
        TreeNode *right;
        bool isDeleted;

        TreeNode(K key, V value) {
            this->key = key;
            this->value = value;
            this->isDeleted = false;
            this->left = nullptr;
            this->right = nullptr;
        }

    };

    TreeNode* root;

    TreeNode* insertRec(TreeNode* node,K key,V value){
        {
            if (node==nullptr) return new TreeNode(key,value);
            if (key < node->key ) {
                node->left = insertRec(node->left,key,value);
            }else if (key > node->key ) {
                node->right = insertRec(node->right,key,value);
            }else {
                node->value = value;
            }
            return node;
        }
    }
    void PrintTree(TreeNode* node) {
        if (node == nullptr) return;
        PrintTree(node->left);
        if (!node->isDeleted) {
            std::cout << node->key << " ";
        }
        PrintTree(node->right);
    }

    TreeNode* findMin(TreeNode* node) {
        if (node == nullptr) return nullptr;
        if (node->isDeleted) return nullptr;




    }


    public:
    void Insert(K key, V value) {
       root = insertRec(root,key,value);
    }

    bool Delete(K key) {
        TreeNode* temp = root;
        while (temp != nullptr) {
            if (key < temp->key) {
                temp = temp->left;
            }else if (key > temp->key) {
                temp = temp->right;
            }else {
                if (temp->isDeleted) return false;
                temp->isDeleted = true;
                return true;
            }
        }

        return false;
    }

    K findMin() {
       TreeNode* node= findMin(root);
        return node->key;
    }

    void PrintTree() {

        PrintTree(root);
    }
};
#endif