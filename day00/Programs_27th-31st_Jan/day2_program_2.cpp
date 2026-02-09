#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from left
            if (!isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from right
            else if (!isalnum(s[right])) {
                right--;
            }
            // Compare characters (ignore case)
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // Characters match
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string test = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(test) ? "true" : "false") << endl;
    return 0;
}
