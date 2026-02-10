#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};





class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        
        ListNode* first = head;
        ListNode* second = prev;
        bool isPalin = true;

        while (second) {
            if (first->val != second->val) {
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        
        curr = prev;
        prev = nullptr;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return isPalin;
    }
};


int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome " << endl;
    } else {
        cout << "The linked list is not a palindrome " << endl;
    }

    
    return 0;
}

