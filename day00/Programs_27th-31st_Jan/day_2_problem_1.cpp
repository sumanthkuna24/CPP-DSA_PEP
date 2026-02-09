
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;

    int writeIndex = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[writeIndex - 1]) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    return writeIndex;
}