/**
 * Problem:
 * Given the root of a binary tree, make a function named Node* invert_tree(Node* root) to invert the tree, and return its root
 *
 * Sample Input:
5
3 1 2
9 -1 -1
20 3 4
15 -1 -1
7 -1 -1

 * Sample Input
7
4 1 2
2 3 4
7 5 6
1 -1 -1
3 -1 -1
6 -1 -1
9 -1 -1

 */

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* left_child;
    Node* right_child;

    Node(int val) {
        this->val = val;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
};

void inversion_func(Node* root) {
    if (root == nullptr) {
        return;
    }

    inversion_func(root->left_child);
    inversion_func(root->right_child);

    Node* temp = root->left_child;
    root->left_child = root->right_child;
    root->right_child = temp;
}

Node* invert_tree(Node* root) {
    Node* res_root = root;
    inversion_func(root);
    return res_root;
}

void printSpace(int level) {
    while (level--) {
        cout << "   ";
    }
}

void printTree(Node* root, int level) {
    if (root == nullptr) {
        return;
    }
    if (root->left_child == nullptr and root->right_child == nullptr) {
        cout << root->val << endl;
        return;
    } else {
        cout << endl;
        printSpace(level);
        cout << "Root: " << root->val << endl;
    }
    if (root->left_child != nullptr) {
        printSpace(level);
        cout << "Left: ";
        printTree(root->left_child, level + 1);
    }

    if (root->right_child != nullptr) {
        printSpace(level);
        cout << "Right: ";
        printTree(root->right_child, level + 1);
    }
}

int main() {
    int n;
    cin >> n;
    Node* all_nodes[n];

    for (int i = 0; i < n; i++) {
        all_nodes[i] = new Node(-1);
    }

    for (int i = 0; i < n; i++) {
        int val, left, right;
        cin >> val >> left >> right;

        all_nodes[i]->val = val;
        if (left > n - 1 or right > n - 1) {
            cout << "Out of index. " << endl;
            break;
        }

        if (left != -1) {
            all_nodes[i]->left_child = all_nodes[left];
        }

        if (right != -1) {
            all_nodes[i]->right_child = all_nodes[right];
        }
    }

    cout << "\nBefore Inversion: ";
    printTree(all_nodes[0], 0);
    Node* new_root = invert_tree(all_nodes[0]);
    cout << "\nAfter Inversion: ";
    printTree(new_root, 0);

    return 0;
}