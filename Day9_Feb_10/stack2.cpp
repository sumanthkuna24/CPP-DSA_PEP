#include <stack>
using namespace std;

class ElevatorEmergencyDisplay {
private:
    stack<long long> st;
    long long currentMin;

public:
    ElevatorEmergencyDisplay() {}

    void enter(int weight) {
        if (st.empty()) {
            st.push(weight);
            currentMin = weight;
        }
        else if (weight >= currentMin) {
            st.push(weight);
        }
        else {
            // Encode
            long long encoded = 2LL * weight - currentMin;
            st.push(encoded);
            currentMin = weight;
        }
    }

    void exit() {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        if (topVal < currentMin) {
            // It was encoded
            currentMin = 2LL * currentMin - topVal;
        }
    }

    int getMinimumWeight() {
        if (st.empty())
            return -1;

        return currentMin;
    }
};
