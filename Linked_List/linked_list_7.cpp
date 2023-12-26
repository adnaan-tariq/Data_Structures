#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at a specified position in the linked list
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node(value);

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        return newNode; // If the position is 1 or the list is empty, the new node becomes the head.
    }

    Node* current = head;
    int currentPos = 1;

    while (current->next != nullptr && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head; // Return the updated head of the list.
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << "  ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Node* head = nullptr;

    // Insert at the end
    head = insertAtPosition(head, 1, 1);
    head = insertAtPosition(head, 2, 2);
    head = insertAtPosition(head, 6, 4);

    // Insert at a specific position
    head = insertAtPosition(head, 5, 3);

    // Display the linked list
    std::cout << "Linked List: ";
    display(head);

    // Don't forget to free memory by deleting the nodes when you're done with the list.
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
