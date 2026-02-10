//Check Palindrome in a Singly Linked List Using ONLY a Stack and ONE Traversal

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


bool isPalindromeSingleTraversal(Node* head) {
    if (!head || !head->next) return true;

    stack<int> st;
    Node* slow = head;
    Node* fast = head;

    
    while (fast && fast->next) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    
    if (fast != nullptr) {
        slow = slow->next;
    }

   
    while (slow) {
        if (st.empty() || st.top() != slow->data) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }

   
    return st.empty();
}
