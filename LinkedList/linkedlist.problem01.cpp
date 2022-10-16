/**
 * @Problem
 * Write down a program that will take n number of input from the users and create a Linear Linked List of n size. Replace all the even numbers in the list with -1 and display the List.

  * Sample Input
  5
  1 3 4 5 6
  * Sample Output
  1-> 3 -> -1 -> 5 -> -1

*/

#include <bits/stdc++.h>
using namespace std;

class List {
   public:
    int val;
    List* next;

    // constructor
    List(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// inserting at the end
void insertValAtEnd(List*& head, int val) {
    List* newNode = new List(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    List* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// printing list function
void printList(List*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    List* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    List* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertValAtEnd(head, x);
    }

    printList(head);
    return 0;
}