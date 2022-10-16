/**
 * @Problem
 *
 *  Given a singly linked list of size N. The task is to reverse every k node (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Sample 2 for clarification). Your task is to complete the function reverseKNodes() which should reverse the linked list in a group of size k and return the head of the modified linked list.

Sample-Input-Output:
8
1 2 2 4 5 6 7 8
4

4->2->2->1->8 ->7->6->5

Explanation
The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the resultant linked list is 4->2->2->1->8->7->6->5.

*/

#include <bits/stdc++.h>
using namespace std;

class LinkedList {
   public:
    int val;
    LinkedList* next;

    // constructor
    LinkedList(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// val insert at the end
void insertAtLast(LinkedList*& head, int val) {
    LinkedList* new_node = new LinkedList(val);
    if (head == NULL) {
        head = new_node;
        return;
    }

    LinkedList* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// printing list
void printLinkedList(LinkedList*& head) {
    if (head == NULL) {
        cout << "List is empty. Please enter some node." << endl;
        return;
    }

    LinkedList* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// reverse linked list with three pointer method (problem is for kth position)
LinkedList* reverseLinkedList(LinkedList*& head, int k) {
    LinkedList* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL) return head;
        temp = temp->next;
    }
    LinkedList* curr_node = head;
    LinkedList* prev_node = NULL;
    LinkedList* next_node = NULL;
    for (int i = 0; i < k; i++) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    // recursive call
    head->next = reverseLinkedList(curr_node, k);
    return prev_node;
}

int main() {
    int n;
    cin >> n;
    LinkedList* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtLast(head, val);
    }
    cout << "Given List: ";
    printLinkedList(head);
    int k;
    cin >> k;
    cout << "Reversed in k portion: ";
    head = reverseLinkedList(head, k);
    printLinkedList(head);
    return 0;
}