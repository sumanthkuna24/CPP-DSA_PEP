#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


Node* reverseList(Node* head) {
    Node* prev = nullptr;      
    Node* current = head;      

    while (current != nullptr) {
        Node* nextNode = current->next; 
        current->next = prev;           
        prev = current;                 
        current = nextNode;             
    }

    return prev; // new 

}