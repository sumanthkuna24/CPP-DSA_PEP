// Live Server Rollback Monitor


# include <bits/stdc++.h>
using namespace std;


int findFirstInvalidOperation(const vector<string>& operations) {
    int activeVersions = 0;  

    for (int i = 0; i < (int)operations.size(); i++) {
        const string& op = operations[i];

        if (op.find("DEPLOY") == 0) {
           
            activeVersions++;
        } 
        else if (op == "ROLLBACK") {
            
            if (activeVersions == 0) {

                return i + 1;
            }
            activeVersions--;
        }
    }


    return -1;  
}

int main() {
    
    vector<string> ops1 = {
        "DEPLOY 1",
        "DEPLOY 2",
        "ROLLBACK",
        "ROLLBACK"
    };

    cout << "Output (Example 1): "
         << findFirstInvalidOperation(ops1) << endl;

    
    vector<string> ops2 = {
        "ROLLBACK",
        "DEPLOY 5"
    };

    cout << "Output (Example 2): "
         << findFirstInvalidOperation(ops2) << endl;

    return 0;
}
