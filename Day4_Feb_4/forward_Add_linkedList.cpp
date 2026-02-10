#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};


int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}


Node* addSameLength(Node* l1, Node* l2, int& carry) {
    if (!l1 && !l2) {
        carry = 0;
        return nullptr;
    }

    Node* nextNode = addSameLength(l1->next, l2->next, carry);

    int sum = l1->data + l2->data + carry;
    Node* curr = new Node(sum % 10);
    curr->next = nextNode;
    carry = sum / 10;

    return curr;
}


Node* addRemaining(Node* head, Node* stop, int& carry, Node* result) {
    if (head == stop) {
        return result;
    }

    Node* nextNode = addRemaining(head->next, stop, carry, result);

    int sum = head->data + carry;
    Node* curr = new Node(sum % 10);
    curr->next = nextNode;
    carry = sum / 10;

    return curr;
}



Node* addTwoNumbersForward(Node* l1, Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    if (len2 > len1) {
        swap(l1, l2);
        swap(len1, len2);
    }

    int diff = len1 - len2;
    Node* curr = l1;
    while (diff--) {
        curr = curr->next;
    }

    int carry = 0;
    Node* result = addSameLength(curr, l2, carry);
    result = addRemaining(l1, curr, carry, result);

    if (carry > 0) {
        Node* newHead = new Node(carry);
        newHead->next = result;
        result = newHead;
    }

    return result;
}



//Add Two Numbers Represented by Singly Linked Lists (Forward Order)