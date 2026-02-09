#include <iostream>
#include <string>
#include "palindrome.cpp"
using namespace std;
void runTest(const string& input, bool expected) {
    bool result = isPalindrome(input);
    cout << "Input: \"" << input << "\"\n";
    cout << "Expected: " << (expected ? "true" : "false")
         << ", Got: " << (result ? "true" : "false") << "\n\n";
}
int main() {
    // 1. Classic palindrome with punctuation
    runTest("A man, a plan, a canal: Panama", true);
    // 2. Clearly not a palindrome
    runTest("race a car", false);
    // 3. Empty string
    runTest("", true);
    // 4. Only spaces
    runTest("     ", true);
    // 5. Only special characters
    runTest("!!!@@@###", false);
    // 6. Single character
    runTest("a", true);
    // 7. Mixed case palindrome
    runTest("NoOn", true);
    // 8. Digits included
    runTest("1a2b2a1", true);
    // 9. Almost palindrome (one mismatch)
    runTest("ab@c#d!ba", false);
    // 10. Long realistic sentence
    runTest("Was it a rat I saw?", true);
    return 0;
}
