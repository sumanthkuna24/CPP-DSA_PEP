
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};



void deleteGivenNode(Node* node) {
    Node* temp = node->next;

   
    node->data = temp->data;

   
    node->next = temp->next;

  
    if (temp->next != nullptr) {
        temp->next->prev = node;
    }

    
    delete temp;
}
