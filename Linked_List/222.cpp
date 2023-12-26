#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node(value);

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int currentPos = 1;

    while (current->next != nullptr && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head; 
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << "nullptr" <<endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtPosition(head, 1, 1);
    head = insertAtPosition(head, 2, 2);
    head = insertAtPosition(head, 4, 4);


    head = insertAtPosition(head, 3, 3);

    std::cout << "Linked List: ";
    display(head);
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
