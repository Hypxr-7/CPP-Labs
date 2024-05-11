#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }


    void insertAtEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }


    void deleteNode(int val) {
        if (head == nullptr) {
            return;
        }
        if (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* curr = head;
        while (curr->next != nullptr && curr->next->val != val) {
            curr = curr->next;
        }
        if (curr->next != nullptr) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }


    void printList() {
        ListNode* curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

ListNode* mergeInBetween(LinkedList list1, LinkedList list2, int a, int b);

int main() {
    LinkedList list1;
    list1.insertAtEnd(10);
    list1.insertAtEnd(1);
    list1.insertAtEnd(13);
    list1.insertAtEnd(6);
    list1.insertAtEnd(9);
    list1.insertAtEnd(5);

    LinkedList list2;
    list2.insertAtEnd(100000);
    list2.insertAtEnd(100001);
    list2.insertAtEnd(100002);

    list1.head = mergeInBetween(list1, list2, 3, 4);

    list1.printList();

    return 0;
}


ListNode* mergeInBetween(LinkedList list1, LinkedList list2, int a, int b) {
    LinkedList newList;
    ListNode* current1 = list1.head;
    for (int i = 0; i < a; ++i){
        newList.insertAtEnd(current1->val);
        current1 = current1->next;
    }

    for (int i = a; i < b + 1; ++i) current1 = current1->next;

    ListNode* current2 = list2.head;
    while (current2 != nullptr){
        newList.insertAtEnd(current2->val);
        current2 = current2->next;
    }

    while (current1 != nullptr){
        newList.insertAtEnd(current1->val);
        current1 = current1->next;
    }

    return newList.head;
}
