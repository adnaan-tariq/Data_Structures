#include <iostream>

using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* prevNode = *head;
    for (int i = 1; i < position - 1 && prevNode != NULL; i++) {
        prevNode = prevNode->next;
    }

    if (prevNode == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning of the linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the linked list
    cout << "Linked list before insertion: ";
    printList(head);

    // Insert a node at position 2
    insertAtPosition(&head, 4, 2);

    // Print the linked list
    cout << "Linked list after insertion: ";
    printList(head);

    return 0;
}
