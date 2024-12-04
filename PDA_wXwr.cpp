#include <iostream>
#include <stack>
using namespace std;

bool isAccepted(string input) {
    stack<char> pdaStack;
    int n = input.length();
    int i = 0;

    // State q0: Push w onto stack
    while (i < n && (input[i] == 'a' || input[i] == 'b')) {
        pdaStack.push(input[i]);
        i++;
    }

    // State q1: Ensure X is encountered
    if (i < n && input[i] == 'X') {
        i++;
    } else {
        return false; // 'X' is missing
    }

    // State q2: Pop for reverse of w (w^r)
    while (i < n) {
        if (pdaStack.empty()) {
            return false; // More characters than the stack
        }
        if (input[i] != pdaStack.top()) {
            return false; // The characters don't match
        }
        pdaStack.pop();
        i++;
    }

    // Acceptance: The stack should be empty and all input processed
    return pdaStack.empty() && i == n;
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (isAccepted(input)) {
        cout << "The string is accepted by the PDA!" << endl;
    } else {
        cout << "The string is not accepted by the PDA!" << endl;
    }

    return 0;
}
