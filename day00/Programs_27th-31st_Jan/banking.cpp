// Banking Transaction Validation System
// Determines whether a transaction is valid and updates account balance

#include <iostream>
using namespace std;

int main() {
    char transactionType;   // 'D' for Deposit, 'W' for Withdrawal
    int transactionAmount;
    int currentBalance;

    cout << "Enter current account balance: ";
    cin >> currentBalance;

    cout << "Enter transaction type (D for Deposit / W for Withdrawal): ";
    cin >> transactionType;

    cout << "Enter transaction amount: ";
    cin >> transactionAmount;

    // Check for zero or negative transaction amount
    if (transactionAmount <= 0) {
        cout << "Transaction Rejected" << endl;
        cout << "Reason: Transaction amount must be greater than zero" << endl;
    }
    // Check for valid transaction type
    else if (transactionType != 'D' && transactionType != 'W') {
        cout << "Transaction Rejected" << endl;
        cout << "Reason: Invalid transaction type" << endl;
    }
    // Deposit transaction
    else if (transactionType == 'D') {
        currentBalance = currentBalance + transactionAmount;
        cout << "Transaction Approved" << endl;
        cout << "Updated Balance: " << currentBalance << endl;
    }
    // Withdrawal transaction
    else if (transactionType == 'W') {
        if (transactionAmount > currentBalance) {
            cout << "Transaction Rejected" << endl;
            cout << "Reason: Insufficient balance" << endl;
        } else {
            currentBalance = currentBalance - transactionAmount;
            cout << "Transaction Approved" << endl;
            cout << "Updated Balance: " << currentBalance << endl;
        }
    }

    return 0;
}
