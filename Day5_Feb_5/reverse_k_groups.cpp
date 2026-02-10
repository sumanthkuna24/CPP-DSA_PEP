// Reverse a Singly Linked List in Groups of K (O(K) Extra Space)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* prevGroupTail = nullptr;
    Node* newHead = nullptr;

    while (curr) {
       
        Node* check = curr;
        int count = 0;
        while (count < k && check) {
            check = check->next;
            count++;
        }
        if (count < k) {
       
            if (prevGroupTail) {
                prevGroupTail->next = curr;
            }
            break;
        }

    
        Node* prev = nullptr;
        Node* groupHead = curr;
        count = 0;
        while (count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

  
        if (!newHead) {
            newHead = prev; 
        }
        if (prevGroupTail) {
            prevGroupTail->next = prev;
        }
        prevGroupTail = groupHead; 
    }

    return newHead ? newHead : head;
}
