#include <stack>
#include <string>
using namespace std;

string checkExpression(string s) {
    stack<char> st;

    bool invalid = false;
    bool redundant = false;

    char prev = '\0';  // track previous character

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Operand
        if (ch >= 'a' && ch <= 'z') {
            st.push(ch);
        }

        // Opening bracket
        else if (ch == '(') {
            st.push(ch);
        }

        // Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            // Invalid cases
            if (i == 0 || prev == '(' || prev == '+' || prev == '-' || prev == '*' || prev == '/') {
                invalid = true;
            }

            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            bool hasOperator = false;

            while (!st.empty() && st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' ||
                    st.top() == '*' || st.top() == '/')
                    hasOperator = true;

                st.pop();
            }

            if (st.empty())
                return "UNBALANCED";

            st.pop(); // remove '('

            if (!hasOperator)
                redundant = true;

            st.push('x'); // treat bracket expression as operand
        }

        prev = ch;
    }

    // After scanning entire expression

    while (!st.empty()) {
        if (st.top() == '(')
            return "UNBALANCED";
        st.pop();
    }

    if (invalid)
        return "INVALID";

    if (redundant)
        return "REDUNDANT";

    return "VALID";
}
