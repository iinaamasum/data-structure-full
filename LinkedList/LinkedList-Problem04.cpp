#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* new_node = new Node(val);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insertInBetween(Node*& head, int val, int pos) {
    Node* new_node = new Node(val);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    int count = 0;
    Node* temp = head;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }
    Node* hold = temp->next;
    temp->next = new_node;
    temp->next->next = hold;
}

int deleteHeadNode(Node*& head) {
    Node* delNode = head;
    head = head->next;
    int delVal = delNode->val;
    delete delNode;
    return delVal;
}

void makeLinearToCircular(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

void printList(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void printCircularList(Node*& head) {
    Node* temp = head;
    if (head == nullptr) {
        cout << "Empty List." << endl;
        return;
    }
    cout << "\nHead Address: " << head << endl;
    cout << "\nval: " << temp->val << " currAdd: " << temp << " nextAdd: " << temp->next;
    cout << " ---> " << endl;
    temp = temp->next;
    while (temp != head) {
        cout << "val: " << temp->val << " currAdd: " << temp << " nextAdd: " << temp->next;
        if (temp->next != nullptr) cout << " ---> " << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n = 4;
    int arr[] = {14, 25, 33, 47};
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        insertAtEnd(head, arr[i]);
    }
    cout << "Created List with default val :::::: ";
    printList(head);
    cout << "a) Insert 40 at between 33, 47 :::::: ";
    insertInBetween(head, 40, 3);
    printList(head);
    int delVal = deleteHeadNode(head);
    cout << "b) Deleted List after deleting " << delVal << " :::::: ";
    printList(head);
    makeLinearToCircular(head);
    cout << "\nc) Printing Linear to circular list: ";
    printCircularList(head);

    return 0;
}

/**
 * input: 4
          14 25 33 47
*/