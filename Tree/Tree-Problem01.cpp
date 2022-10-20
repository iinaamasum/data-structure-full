/**
 * Problem:
 * Given the roots of two binary trees, write a function named bool isSame(Node* root1, Node* root2) which will take two roots and check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

/**
 * sample input:
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
5 -1 -1

 * input 2
3
0 1 2
1 -1 -1
2 -1 -1
3
0 1 2
1 -1 -1
2 -1 -1

 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int val) {
        this->val = val;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

void printSpace(int level) {
    while (level--) {
        cout << "   ";
    }
}

void printTree(TreeNode *root, int level) {
    if (root == nullptr) {
        return;
    }
    if (root->leftChild == nullptr and root->rightChild == nullptr) {
        cout << root->val << endl;
        return;
    } else {
        cout << endl;
        printSpace(level);
        cout << "Root: " << root->val << endl;
    }
    if (root->leftChild != nullptr) {
        printSpace(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != nullptr) {
        printSpace(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

bool isSame(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr or root2 == nullptr) {
        return true;
    }

    if (root1 != nullptr and root2 != nullptr) {
        if (root1->val == root2->val) {
            return isSame(root1->leftChild, root2->leftChild) and
                   isSame(root1->rightChild, root2->rightChild);

        } else {
            return false;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    TreeNode *nodes1[n];

    for (int i = 0; i < n; i++) {
        nodes1[i] = new TreeNode(-1);
    }

    for (int i = 0; i < n; i++) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes1[i]->val = val;
        if (left > n - 1 or right > n - 1) {
            cout << "Invalid index provided." << endl;
            break;
        }

        if (left != -1) {
            nodes1[i]->leftChild = nodes1[left];
        }
        if (right != -1) {
            nodes1[i]->rightChild = nodes1[right];
        }
    }
    int m;
    cin >> m;
    TreeNode *nodes2[m];
    for (int i = 0; i < m; i++) {
        nodes2[i] = new TreeNode(-1);
    }

    for (int i = 0; i < m; i++) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes2[i]->val = val;
        if (left > m - 1 or right > m - 1) {
            cout << "Invalid index provided." << endl;
            break;
        }

        if (left != -1) {
            nodes2[i]->leftChild = nodes2[left];
        }
        if (right != -1) {
            nodes2[i]->rightChild = nodes2[right];
        }
    }

    cout << "\nPrinting Tree 1: ";
    printTree(nodes1[0], 0);

    cout << "\nPrinting Tree 2: ";
    printTree(nodes2[0], 0);

    if (isSame(nodes1[0], nodes2[0])) {
        cout << "\nTrees are same." << endl;
    } else {
        cout << "\nTrees are different." << endl;
    }

    return 0;
}