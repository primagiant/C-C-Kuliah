#include <iostream>
using namespace std;

class Node {
   public:
    int value;
    Node *left;
    Node *right;

    Node() {
        right = left = NULL;
    }
};

class BinaryTree {
   public:
    Node *root;

    BinaryTree() {
        root = NULL;
    }

    // Insert
    void insert(int inValue) {
        root = insert(inValue, root);
    }

    // Pointer Insert Function
    Node *insert(int inValue, Node *tmp) {
        // Jika node null
        if (tmp == NULL) {
            tmp = new Node();
            tmp->value = inValue;
        } else if (inValue < tmp->value) {
            tmp->left = insert(inValue, tmp->left);
        } else if (inValue > tmp->value) {
            tmp->right = insert(inValue, tmp->right);
        }
        return tmp;
    }

    // Preorder Tranversal
    void preOrderTranversal() {
        preOrderTranversal(root);
    }

    void preOrderTranversal(Node *tmp) {
        if (tmp != NULL) {
            cout << tmp->value << " - ";
            preOrderTranversal(tmp->left);
            preOrderTranversal(tmp->right);
        }
    }

    // Inorder Tranversal
    void inOrderTranversal() {
        inOrderTranversal(root);
    }

    void inOrderTranversal(Node *tmp) {
        if (tmp != NULL) {
            inOrderTranversal(tmp->left);
            cout << tmp->value << " - ";
            inOrderTranversal(tmp->right);
        }
    }

    // Postorder Tranversal
    void postOrderTranversal() {
        postOrderTranversal(root);
    }

    void postOrderTranversal(Node *tmp) {
        if (tmp != NULL) {
            postOrderTranversal(tmp->left);
            postOrderTranversal(tmp->right);
            cout << tmp->value << " - ";
        }
    }

    // Search
    Node *search(int searchValue) {
        return search(searchValue, root);
    }

    Node *search(int searchValue, Node *tmp) {
        if (tmp == NULL)
            return NULL;

        if (searchValue < tmp->value)
            return search(searchValue, tmp->left);

        if (searchValue > tmp->value)
            return search(searchValue, tmp->right);

        if (searchValue == tmp->value)
            return tmp;
    }

    // Find Min
    Node *findMin() {
        return findMin(root);
    }

    Node *findMin(Node *tmp) {
        if (tmp->left == NULL) {
            return tmp;
        } else {
            return findMin(tmp->left);
        }
    }

    // Find Max
    Node *findMax() {
        return findMax(root);
    }

    Node *findMax(Node *tmp) {
        if (tmp->right == NULL) {
            return tmp;
        } else {
            return findMax(tmp->right);
        }
    }

    // Delete Node
    Node *deleteNode(int target) {
        root = deleteNode(target, root);
    }

    Node *deleteNode(int target, Node *tmp) {
        if (tmp == NULL)
            return tmp;

        if (target < tmp->value) {
            tmp->left = deleteNode(target, tmp->left);
        } else if (target > tmp->value) {
            tmp->right = deleteNode(target, tmp->right);
        } else if (target == tmp->value) {
            // jika dia adalah leaf
            if (tmp->left == NULL && tmp->right == NULL) {
                tmp = NULL;
            }
            // jika hanya ada child sebelah kiri
            else if (tmp->left != NULL && tmp->right == NULL) {
                tmp = tmp->left;
            }
            // jika hanya ada child sebelah kanan
            else if (tmp->left == NULL && tmp->right != NULL) {
                tmp = tmp->right;
            }
            // jika memiliki dua child
            else {
                Node *minNode = findMin(tmp->right);
                tmp->value = minNode->value;
                tmp->right = deleteNode(minNode->value, tmp->right);
            }
        }
        return tmp;
    }
};