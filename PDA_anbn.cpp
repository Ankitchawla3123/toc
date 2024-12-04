#include <iostream>
#include <stack>
using namespace std;

bool isAccepted(string input) {
    stack<char> pdaStack;
    int n = input.length();
    int i = 0;

    // State q0: Push 'a' to stack
    while (i < n && input[i] == 'a') {
        pdaStack.push('a');
        i++;
    }

    // State q1: For each 'b', pop 'a' from stack
    while (i < n && input[i] == 'b') {
        if (pdaStack.empty()) {
            return false; // More 'b's than 'a's
        }
        pdaStack.pop();
        i++;
    }

    // Check if we have reached the end of the string and the stack is empty
    return i == n && pdaStack.empty();
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
