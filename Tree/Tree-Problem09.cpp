/**
 * Problem:
 * A binary tree is uni-valued if every node in the tree has the same value. Given the root of a binary tree, make a function named bool is_unival(Node* root) and return true if the given tree is uni-valued, or false otherwise.
 *
 * Sample Input:
5
3 1 2
9 -1 -1
20 3 4
15 -1 -1
7 -1 -1

 * Sample Input:
6
1 1 2
1 3 4
1 -1 5
1 -1 -1
1 -1 -1
1 -1 -1


*/

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool is_unival(Node* root) {
    if (root == nullptr) {
        return false;
    }

    int uni_val = root->val;

    queue<Node*> q;
    queue<int> res;
    q.push(root);
    q.push(nullptr);
    int turn = false;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != nullptr) {
            if (temp->val != uni_val) {
                return false;
            }

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }

        } else {
            if (!q.empty()) {
                q.push(nullptr);
            }
        }
    }
    return true;
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
            cout << "Invalid indexing." << endl;
            break;
        }

        if (left != -1) {
            all_nodes[i]->left = all_nodes[left];
        }

        if (right != -1) {
            all_nodes[i]->right = all_nodes[right];
        }
    }
    bool res = is_unival(all_nodes[0]);
    if (res) {
        cout << "\nThis is an uni-valued tree.\n"
             << endl;
    } else {
        cout << "\nThis is not an uni-valued tree.\n"
             << endl;
    }
    return 0;
}