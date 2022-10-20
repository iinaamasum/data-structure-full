#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack {
    int size = 0;
    Node *head;
    Node *top;

   public:
    Stack() {
        head = nullptr;
        top = nullptr;
    }
    // push
    void Push(int val) {
        if (head == nullptr) {
            top = head = new Node(val);
            return;
        }

        Node *newNode = new Node(val);
        newNode->prev = top;
        top->next = newNode;
        top = top->next;
        size++;
    }

    // pop
    int Pop() {
        if (top == nullptr) {
            cout << "Underflow. ";
            return -1;
        } else if (top == head) {
            Node *delNode = head;
            int delVal = delNode->val;
            top = head = nullptr;
            return delVal;
        }

        Node *delNode = top;
        top = top->prev;
        int delVal = delNode->val;
        delete delNode;
        return delVal;
    }

    // empty
    bool isEmpty() {
        if (top == nullptr) return true;
        return false;
    }

    //  top
    int Top() {
        if (top == nullptr) {
            cout << "Empty." << endl;
            return -1;
        }

        return top->val;
    }
};

int main() {
    Stack st;
    int lastDay = 5;
    int x = lastDay + 5, y = x + 3, z = y + x;

    st.Push(x + y);
    st.Push(y + z);
    cout << "pop val: " << st.Pop() << endl;
    st.Push(y * z);
    st.Push(x * y);
    cout << "pop val: " << st.Pop() << endl;
    cout << "pop val: " << st.Pop() << endl;

    return 0;
}