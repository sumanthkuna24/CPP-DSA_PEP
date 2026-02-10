#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


int cycleLength(Node* head) {
    if (head == nullptr) return 0;

    Node* slow = head;
    Node* fast = head;

    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
           
            int length = 1;
            Node* temp = slow->next;

            while (temp != slow) {
                length++;
                temp = temp->next;
            }
            return length;
        }
    }

    
    return 0;
}

//Detect Cycle Length in a Singly Linked List