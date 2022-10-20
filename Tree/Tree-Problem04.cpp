/**
 * Problem:
 * Given the root of a binary tree, make a function named bool isSymmetric(Node* root) check whether it is a mirror of itself (i.e., symmetric around its center).

Sample Input:
7
1 1 2
2 3 4
2 5 6
3 -1 -1
4 -1 -1
4 -1 -1
3 -1 -1

Sample input:
5
1 1 2
2 -1 3
2 -1 4
3 -1 -1
3 -1 -1


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

bool checkSymmetric(Node* root1, Node* root2) {
    if (root1 == nullptr and root2 == nullptr) {
        return true;
    }

    if (root1 != nullptr and root2 != nullptr) {
        if (root1->val == root2->val) {
            return checkSymmetric(root1->left_child, root2->right_child) and checkSymmetric(root1->right_child, root2->left_child);
        }

        else {
            return false;
        }
    }

    else {
        return false;
    }
}

bool isSymmetric(Node* root) {
    return checkSymmetric(root, root);
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
            cout << "Index is greater than number of nodes." << endl;
            break;
        }

        if (left != -1) {
            all_nodes[i]->left_child = all_nodes[left];
        }

        if (right != -1) {
            all_nodes[i]->right_child = all_nodes[right];
        }
    }
    cout << endl;
    if (isSymmetric(all_nodes[0])) {
        cout << "This tree is a symmetric tree." << endl;
    } else {
        cout << "This tree is not a symmetric tree." << endl;
    }

    return 0;
}