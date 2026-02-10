#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


bool isPalindrome(Node* head) {

    if (head == nullptr || head->next == nullptr)
        return true;

   
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    
    Node* tempSecond = secondHalf;
    bool palindrome = true;

    while (tempSecond != nullptr) {
        if (firstHalf->data != tempSecond->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

 
    slow->next = reverseList(secondHalf);

    return palindrome;
}

