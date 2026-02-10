//Delete Every Node Which Has a Greater Value on Its Right Side (Stack-Based Reasoning)
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


Node* deleteNodesWithGreaterRight(Node* head) {
    if (!head || !head->next) return head;

    stack<Node*> st;
    Node* curr = head;

    
    while (curr) {
        while (!st.empty() && st.top()->data < curr->data) {
            st.pop(); 
        }
        st.push(curr);
        curr = curr->next;
    }

   
    Node* newHead = nullptr;
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        node->next = newHead;
        newHead = node;
    }

    return newHead;
}

