// how binary trees work 
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

struct BSTNode {
    int value;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;
};

class BinarySearchTree {
private:
    std::unique_ptr<BSTNode> root; // root of tree

    void addRecursive(std::unique_ptr<BSTNode>& node, int value) {
        if (!node) {
            node = std::make_unique<BSTNode>();
            node->value = value;
            return;
        }

        if (value <= node->value) {
            addRecursive(node->left, value);
        } else {
            addRecursive(node->right, value);
        }
    }

    BSTNode* findMinNode(BSTNode* node) {
        if (!node->left) {
            return node;
        }
        return findMinNode(node->left.get());
    }

    void removeRecursive(std::unique_ptr<BSTNode>& node, int value) {
        if (!node) {
            return;
        }
        // in order traversal 
        if (value < node->value) {
            removeRecursive(node->left, value);
        } else if (value > node->value) {
            removeRecursive(node->right, value);
        } else {
            if (!node->left) {
                node = std::move(node->right);
            } else if (!node->right) {
                node = std::move(node->left);
            } else {
                BSTNode* successor = findMinNode(node->right.get());
                node->value = successor->value;
                removeRecursive(node->right, successor->value);
            }
        }
    }

    void inOrderTraversalRecursive(const BSTNode* node) {
        if (node) {
            inOrderTraversalRecursive(node->left.get());
            cout << node->value << " ";
            inOrderTraversalRecursive(node->right.get());
        }
    }

public:
    void add(int value) {
        addRecursive(root, value);
    }

    void remove(int value) {
        removeRecursive(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root.get());
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.add(5);
    bst.add(50);
    bst.add(7);
    bst.add(20);
    bst.add(50);
    bst.add(60);
    bst.add(110);

    cout << "In-order traversal: ";
    bst.inOrderTraversal();  // Should output: 20 30 40 50 60 70 80

    bst.remove(50);
    bst.remove(7);

    cout << "In-order traversal after removal: ";
    bst.inOrderTraversal();  // Should output: 20 40 50 60 80

    return 0;
}
