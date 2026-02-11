#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    // Base condition
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    // Remove top ele
    int temp = st.top();
    st.pop();

    // Recursive call
    insertSorted(st, x);

    // Put back removed ele
    st.push(temp);
}

void sortStack(stack<int>& st) {
    // Base con
    if (st.empty())
        return;

    // Remove top ele
    int temp = st.top();
    st.pop();

    // Sort 
    sortStack(st);

    // Insert removed element correctly
    insertSorted(st, temp);
}
