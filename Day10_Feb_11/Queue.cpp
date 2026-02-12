#include <stack>
using namespace std;

class WaterLine {
private:
    stack<int> st;

public:

    void join(int x) {
        st.push(x);
    }


    int serve() {
        if (st.empty())
            return -1;

        int n = st.size();

        for (int i = 0; i < n - 1; i++) {
            int topVal = st.top();
            st.pop();
            st.push(topVal); 
        }

       
        return -1;
    }
};
