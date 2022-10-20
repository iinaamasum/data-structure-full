/**
 * Problem:
 * Given a binary tree, you need to make a function named int second_minimum(Node* root) and return the second minimum value in all the nodes' value in the whole tree. If no such second minimum value exists, output -1 instead.
 *
 * Sample Input:
5
2 1 2
2 -1 -1
5 3 4
5 -1 -1
7 -1 -1

 * Sample Input:
6
1 1 2
1 3 4
1 -1 5
1 -1 -1
1 -1 -1
1 -1 -1

 * Sample Input
3
2 1 2
2 -1 -1
2 -1 -1


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

int second_minimum(Node* root) {
    if (root == nullptr) {
        cout << "Empty Tree." << endl;
        return -1;
    }
    int minVal = root->val;
    int secondMinVal = -1;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != nullptr) {
            if (temp->val > minVal) {
                if (secondMinVal == -1) {
                    secondMinVal = temp->val;
                } else {
                    secondMinVal = min(temp->val, secondMinVal);
                }
            }

            else if (temp->val < minVal) {
                secondMinVal = minVal;
                minVal = temp->val;
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
    if (minVal == secondMinVal) {
        return -1;
    } else {
        return secondMinVal;
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

    cout << endl;
    cout << second_minimum(all_nodes[0]) << endl;

    return 0;
}