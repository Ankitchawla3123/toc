#include <iostream>
#include <string>

using namespace std;

bool simulateFA(const string& input) {
    int state = 0; // initial state (q0)
    
    for (char c : input) {
        switch(state) {
            case 0: // q0
                if (c == '1') state = 1;
                break;
            case 1: // q1
                if (c == '1') state = 2;
                else state = 0;
                break;
            case 2: // q2
                if (c == '1') state = 3;
                else state = 0;
                break;
            case 3: // q3
                return true;
        }
    }
    return (state == 3); // Accept if State q3
}

int main() {
    string input;
    cout << endl << "Enter a binary string: ";
    cin >> input;

    if (simulateFA(input)) {
        cout << "Accepted: String contains '111'" << endl;
    } else {
        cout << "Rejected: String does not contain '111'" << endl;
    }

    return 0;
}
