// Given an integer input, store it in a signed int variable
// and observe what happens when input exceeds int range

#include <iostream>
#include <climits>
using namespace std;

// Function to store long long into signed int
int storedInSignedInt(long long input) {
    int stored = (int)input;
    return stored;
}

// Structure to hold test cases
struct TestCase {
    long long input;
    int expected;
};

// Function to run predefined test cases
void runPredefinedTest() {
    cout << "Running predefined test cases:\n\n";

    TestCase tests[] = {
        {2147483647LL, 2147483647},    // INT_MAX
        {2147483648LL, -2147483648},   // overflow
        {4294967295LL, -1},            // wrap around
        {-2147483649LL, 2147483647}    // underflow
    };

    int totalTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < totalTests; i++) {
        int result = storedInSignedInt(tests[i].input);

        cout << "Test Case " << i + 1 << endl;
        cout << "Input Value      : " << tests[i].input << endl;
        cout << "Stored in int    : " << result << endl;
        cout << "Expected Output  : " << tests[i].expected << endl;

        if (result == tests[i].expected)
            cout << "Status           : PASS\n\n";
        else
            cout << "Status           : FAIL\n\n";
    }
}

// Function for user-defined test cases
void runCustomTest() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long input;
        cout << "\nEnter input value: ";
        cin >> input;

        int result = storedInSignedInt(input);
        cout << "Stored value in int: " << result << endl;
    }
}

int main() {
    int choice;

    cout << "1. Run predefined test cases\n";
    cout << "2. Run custom test cases\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        runPredefinedTest();
    else if (choice == 2)
        runCustomTest();
    else
        cout << "Invalid choice\n";

    return 0;
}
