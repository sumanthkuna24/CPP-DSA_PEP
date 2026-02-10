#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


Node* removeNthFromEnd(Node* head, int n) {

    if (head == nullptr) return nullptr;

    Node* fast = head;
    Node* slow = head;

    
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) return head; 
        fast = fast->next;
    }

   
    if (fast == nullptr) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

   
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }


    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return head;
}

//Remove N-th Node from End of Linked List (Edge-Strict)

