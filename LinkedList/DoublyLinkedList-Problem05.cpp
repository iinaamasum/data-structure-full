#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
}

void printDoublyLinkedListFromHead(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "In Forward direction: ";
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void printDoublyLinkedListFromTail(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << "In reverse direction: ";
    while (temp != head->prev) {
        cout << temp->val;
        if (temp->prev != head->prev) cout << " <- ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int n = 5;
    int arr[] = {4, 6, 9, 14, 18};
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        insertAtEnd(head, arr[i]);
    }
    printDoublyLinkedListFromHead(head);
    printDoublyLinkedListFromTail(head);

    return 0;
}