#include <iostream>
#include <algorithm>

template<class T>
class AVLTree {

public:
    AVLTree() : root(nullptr) {};


private:
    struct AVLNode {
        T data;
        AVLNode* left;
        AVLNode* right;
        int height;
      AVLNode( const T& data, AVLNode* left = nullptr, AVLNode* right = nullptr, int height = 0) : data(data), left(left), right(right), height(height) {};
    };

    AVLNode* root;

    void rotateRight( AVLNode*& k1) {
        AVLNode* k2 = k1->left;
        k1->left = k2->right;
        k2->right = k1;
        k1->height = 1 + std::max(height(k1->left), height(k1->right));
        k2->height = 1 + std::max(height(k2->left), height(k2->right));
        k1 = k2;
    }

    void rotateLeft( AVLNode*& k1) {
        AVLNode* k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = 1 + std::max(height(k1->left), height(k1->right));
        k2->height = 1 + std::max(height(k2->left), height(k2->right));
        k1 = k2;
    }

    void leftRightRotate( AVLNode*& k1) {
        rotateLeft(k1->left);
        rotateRight(k1);
    }

    void rightLeftRotate( AVLNode*& k1) {
        rotateRight(k1->right);
        rotateLeft(k1);
    }

    void printTree(AVLNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        printTree(node->left);
        printTree(node->right);
    }
    void insert(const T& data, AVLNode* &node) {
        if (node == nullptr)
            node = new AVLNode(data);
        else if (data < node->data) {
            insert(data, node->left); // insert on left
            //check height
            if (height(node->left) - height(node->right) == 2) {
                if (data < node->left->data) {
                    rotateRight(node);
                }else {
                    leftRightRotate(node);
                }
            }
            //rotate
        }else if (data > node->data) {
            insert(data,node->right);//insert element
            //check height
            if (height(node->right) - height(node->left) == 2) {
                if (data > node->right->data) {
                    rotateLeft(node);
                }else {
                    rightLeftRotate(node);
                }
            }

        }else {
        }
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    void clear(AVLNode* node) {
        if (node == nullptr)return;
        clear(node->left);
        clear(node->right);
        delete node;
    }



public:
    int height(AVLNode* node) {
        return node == nullptr ? -1 : node->height;
    }

    void insert(const T& data) {
        return insert(data,root);
    }

   void iterativeInsert(const T& data) {
        if (root == nullptr) {
            root = new AVLNode(data);
            return;
        }

        AVLNode* curr = root;
        std::stack<AVLNode*> stack;

        while (curr != nullptr) {
            stack.push(curr);
            if (data < curr->data) {
                curr = curr->left;
            }else if (data > curr->data) {
                curr = curr->right;
            }else {
                curr->data = data;
                return;
            }
        }

        AVLNode* node = new AVLNode(data);
        AVLNode* temp = stack.top();
        if (data < temp->data) {
            temp->left = node;
        } else {
            temp->right = node;
        }

        while (!stack.empty()) {
            temp = stack.top();

            if (height(temp->left) - height(temp->right) == 2) {
                if (data < temp->left->data) {
                    rotateRight(node);
                }
                else {
                    leftRightRotate(node);
                }
            }else if (data > temp->data) {
                if (data > temp->right->data) {
                    rotateLeft(node);
                }else {
                    rightLeftRotate(node);
                }
            }
        }
    }


    void print() {
        printTree(root);
    }



    ~AVLTree() {
        clear(root);
    }


};
