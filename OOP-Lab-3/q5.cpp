#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

// implementation of linked list
// used from https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/ 

class Node { 
public: 
    int data; 
    Node* next; 
  
    Node() { 
        data = 0; 
        next = NULL; 
    } 
   
    Node(int data) { 
        this->data = data; 
        this->next = NULL; 
    } 
}; 
   
class Linkedlist { 
    Node* head; 
  
public: 
    Linkedlist() { head = NULL; } 
    
    void printRecursive(Node* first);

    void insertNode(int data) { 

        Node* newNode = new Node(data); 
    
        if (head == NULL) { 
            head = newNode; 
            return; 
        } 
    
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
    
        temp->next = newNode; 
    } 
  
    void printList() { 
        Node* temp = head; 
    
        if (head == NULL) { 
            cout << "List empty" << endl; 
            return; 
        } 
    
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 
  
    void deleteNode(int nodeOffset) { 
        Node *temp1 = head, *temp2 = NULL; 
        int ListLen = 0; 
    
        if (head == NULL) { 
            cout << "List empty." << endl; 
            return; 
        } 
    
        while (temp1 != NULL) { 
            temp1 = temp1->next; 
            ListLen++; 
        } 

        if (ListLen < nodeOffset) { 
            cout << "Index out of range"
                << endl; 
            return; 
        } 
    
        temp1 = head; 
    
        if (nodeOffset == 1) { 
            head = head->next; 
            delete temp1; 
            return; 
        } 
    
        while (nodeOffset-- > 1) { 
            temp2 = temp1; 
            temp1 = temp1->next; 
        } 
    
        temp2->next = temp1->next; 
    
        delete temp1; 
    }

    Node* reverseList();
}; 

// recursive print function
void Linkedlist::printRecursive(Node* first){
    if (first != NULL) {
        cout << first->data;
        printRecursive(first->next);
    }
}

int main(){
    Linkedlist l;
    l.insertNode(0);
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);

    l.printList();
    cout << endl;

    return 0;
}