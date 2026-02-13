#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool suspiciousRepeat(vector<int>& ids, int K) {

    unordered_set<int> window;  

    for (int i = 0; i < ids.size(); i++) {

     
        if (window.find(ids[i]) != window.end()) {
            return true;   
        }

      
        window.insert(ids[i]);

        
        if (window.size() > K) {
            window.erase(ids[i - K]);
        }
    }

    return false;
}
