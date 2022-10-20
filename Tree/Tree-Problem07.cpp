/**
 * Problem:
 * Given the root of a binary tree, make a function named void average_level(Node* root) and print the average value of the nodes on each level.
 *
 * Sample input:
7
4 1 2
2 3 4
7 5 6
1 -1 -1
3 -1 -1
6 -1 -1
9 -1 -1

 * Sample input:
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

void average_level(Node* root) {
    if (root == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    float sum = 0;
    int count = 0;

    while (!q.empty()) {
        Node* check_node = q.front();
        q.pop();

        if (check_node != nullptr) {
            sum += check_node->val;
            count++;
            if (check_node->left_child != nullptr) {
                q.push(check_node->left_child);
            }

            if (check_node->right_child != nullptr) {
                q.push(check_node->right_child);
            }
        } else {
            if (!q.empty()) {
                cout << sum / count << " ";
                sum = 0;
                count = 0;
                q.push(nullptr);
            }
        }
    }
    cout << sum / count << endl
         << endl;
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
            all_nodes[i]->left_child = all_nodes[left];
        }

        if (right != -1) {
            all_nodes[i]->right_child = all_nodes[right];
        }
    }

    cout << "\nAverage value: ";
    average_level(all_nodes[0]);

    return 0;
}