/**
 *  Given a linked list of size K and two integers M and N. Traverse the linked list such that you retain M nodes then delete the next N nodes, continue the same till the end of the linked list.

Sample-Input:
8 2 2
1 2 3 4 5 6 7 8

Output:
1->2->5->6

*/

#include <bits/stdc++.h>
using namespace std;

class LinkedList {
   public:
    int val;
    LinkedList *next;

    // constructor with val parameter
    LinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void insertValAtLast(LinkedList *&head, int val) {
    LinkedList *new_node = new LinkedList(val);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    LinkedList *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printLinkedList(LinkedList *&head) {
    if (head == nullptr) {
        cout << "The linked list is empty. Please enter some value first." << endl;
        return;
    }

    LinkedList *temp = head;

    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNodes(LinkedList *&head, int m, int n, int k) {
    if (head == nullptr) {
        cout << "List is empty. Underflow." << endl;
        return;
    }

    // no need to return new head as first few nodes will be unchanged.
    LinkedList *temp = head;

    int inc_m = 1, inc_n = 1;
    while (temp != nullptr) {
        if (inc_m < m) {
            inc_m++;
            temp = temp->next;
            continue;
        } else if (inc_n <= n) {
            if (temp->next == nullptr) {
                temp = nullptr;
                return;
            }
            temp->next = temp->next->next;
            if (inc_n == n) {
                inc_n = 0;
                inc_m = 0;
            }
            inc_n++;
        }
    }
}

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    LinkedList *head = nullptr;
    while (k--) {
        int x;
        cin >> x;
        insertValAtLast(head, x);
    }
    printLinkedList(head);

    deleteNodes(head, m, n, k);
    printLinkedList(head);

    return 0;
}