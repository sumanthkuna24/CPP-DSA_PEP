#include <iostream>
#include <vector>
#include "day_2_problem_1.cpp"

using namespace std;

void test(vector<int> arr) {
    int len = removeDuplicates(arr);

    cout << "[ ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "] -> Length = " << len << endl;
}

int main() {
    test({1, 1, 2, 2, 2, 3});
    test({1, 1, 1});
    test({1, 2, 3, 4});
    test({5});
    test({});

    return 0;
}