#include <iostream>
#include <string>

using namespace std;

bool simulateFA(const string& input) {
    int state = 0; // initial state (q0)
    
    for (char c : input) {
        switch(state) {
            case 0: // q0
                if (c == 'a') state = 1;
                break;
            case 1: // q1
                if (c == 'a') state = 2;
                else state = 0;
                break;
            case 2: // q2
                return true;
        }
    }
    return (state == 2); // Accept if State q2
}

int main() {
    string input;
    cout << endl << "Enter a string: ";
    cin >> input;

    if (simulateFA(input)) {
        cout << "Rejected: String contains 'aa'" << endl;
    } else {
        cout << "Accepted: String does not contain 'aa'" << endl;
    }

    return 0;
}
