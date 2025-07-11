#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void traverseForward(Node* head) {
    cout << "Forward Traversal: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void traverseBackward(Node* head) {
    if (!head) return;

    while (head->next) {
        head = head->next;
    }

    cout << "Backward Traversal: ";
    while (head) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    traverseForward(head);
    traverseBackward(head);

    return 0;
}
