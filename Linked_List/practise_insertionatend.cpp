#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

};
Node* head = NULL;
void insert(int value){
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next=NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        Node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next  = newnode;
    }
}
void display(){
    Node *temp = head;
    cout<<"The elements in the list are : ";
    while (temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
        }
        cout<<endl;
        
}
int main(){
    //insertion of nodes into linkedlist
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    return 0;
}