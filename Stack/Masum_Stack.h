#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* prev;

    // constructor for value initialization
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack {
   public:
    Node* head;
    Node* top;
    int size = 0;

    Stack() {
        head = nullptr;
        top = nullptr;
    }

    // operations
    void Push(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = top = new_node;
            return;
        }
        top->next = new_node;
        top = top->next;
        size++;
    }

    int Pop() {
        Node* del_node = top;

        if (head == nullptr) {
            cout << "Underflow. returning -1 as val." << endl;
            return -1;
        }

        if (head == top) {
            cout << "Stack is now empty." << endl;
            head = top = nullptr;
            return del_node->val;
        }

        top = del_node->prev;
        top->next = nullptr;
        size--;
        return del_node->val;
    }

    bool IsEmpty() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return true;
        }
        return false;
    }

    int StackSize() {
        return size;
    }

    int Top() {
        if (top == nullptr) {
            cout << "Stack is empty. So returning -1 as top." << endl;
            return -1;
        }
        return top->val;
    }

    int mid() {
        Node* temp = head;
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        int mid = size / 2;
        if (size % 2) {
            cout << "Size is odd. Mid elements are 2 and returning the first mid which is: ";
            mid++;
        }
        while (mid--) {
            temp = temp->next;
        }
        return temp->val;
    }
};
