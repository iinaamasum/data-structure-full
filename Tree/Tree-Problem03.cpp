/**
 * Given the root of a binary tree, make a function named void level_order_reverse(Node* root) and output the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
For example:

Sample Input:
5
3 1 2
9 -1 -1
20 3 4
15 -1 -1
7 -1 -1
Output: 15 7 9 20 3

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

void level_order_reverse(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<int> s;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp != nullptr) {
            s.push(temp->val);
            if (temp->right_child != nullptr) {
                q.push(temp->right_child);
            }
            if (temp->left_child != nullptr) {
                q.push(temp->left_child);
            }
        } else {
            if (!q.empty()) {
                q.push(nullptr);
            }
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
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
    cout << "\nLevel Order Reverse: ";
    level_order_reverse(all_nodes[0]);

    return 0;
}