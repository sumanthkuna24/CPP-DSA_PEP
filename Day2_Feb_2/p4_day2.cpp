#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Merges two sorted linked lists in-place
// Returns head of merged sorted list
Node* mergeSortedLists(Node* head1, Node* head2) {

    // Edge cases
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    // Dummy node to simplify head handling
    Node dummy(0);
    Node* tail = &dummy;

    Node* p1 = head1;
    Node* p2 = head2;

    // Merge while both lists have nodes
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data <= p2->data) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (p1 != nullptr) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    return dummy.next;
}