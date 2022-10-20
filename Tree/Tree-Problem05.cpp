/**
 * Problem:
 * Given the root of a binary tree, make a function named void zigzag_order(Node* root) and output the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left, then again left to right for the next level and this order will continue).

 * Sample input:
 7
1 1 2
2 3 4
2 5 6
3 -1 -1
4 -1 -1
4 -1 -1
3 -1 -1

 * Sample Input
5
3 1 2
9 -1 -1
20 3 4
15 -1 -1
7 -1 -1

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

void zigzag_order(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    queue<int> res;
    q.push(root);
    q.push(nullptr);
    int turn = false;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != nullptr) {
            res.push(temp->val);
            if (turn) {
                if (temp->left_child != nullptr) {
                    q.push(temp->left_child);
                }

                if (temp->right_child != nullptr) {
                    q.push(temp->right_child);
                }
            } else {
                if (temp->right_child != nullptr) {
                    q.push(temp->right_child);
                }
                if (temp->left_child != nullptr) {
                    q.push(temp->left_child);
                }
            }
        } else {
            if (!q.empty()) {
                q.push(nullptr);
                turn = true;
            }
        }
    }
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
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
            cout << "\nLinkage can't be greater than n-1" << endl;
            break;
        }

        if (left != -1) {
            all_nodes[i]->left_child = all_nodes[left];
        }

        if (right != -1) {
            all_nodes[i]->right_child = all_nodes[right];
        }
    }

    cout << "\nPrinting in zigzag order: ";
    zigzag_order(all_nodes[0]);

    return 0;
}