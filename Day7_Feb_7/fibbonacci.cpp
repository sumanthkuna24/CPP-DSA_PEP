

#include <iostream>
using namespace std;

int calculateDifference(int start, int end, int user_value) {
    int sum_odd = 0;
    int sum_even = 0;
    int a = 0;
    int b = 1;
    int c;

    for (int i = start; i <= end; ++i) {
        c = a + b;
        a = b;
        b = c;

        if (a % 2 == 0) {
            sum_even += a;
        } else {
            sum_odd += a;
        }
    }

    int difference = abs(sum_odd - sum_even);
    return difference * user_value;
}

int main() {
    int start = 0;
    int end = 10;
    int user_value = 5;

    int result = calculateDifference(start, end, user_value);
    cout << "The difference between the sum of odd and even terms in the Fibonacci series multiplied by user value is: " << result << std::endl;

    return 0;
}




