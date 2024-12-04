#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the current tape and state details
void printStep(int step, const string& tape, int head, const string& currentState, const string& nextState) {
    cout << "Step: " << step << " | Tape: " << tape << " | Head: " << head
         << " | Current State: " << currentState << " -> Next State: " << nextState << endl;
}

// Turing Machine simulation
void incrementBinary(string binary) {
    // Initialize tape, head, and state
    string tape = binary + " "; // Add blank space at the end of tape
    int head = tape.length() - 2; // Start at the last bit
    string currentState = "q0";
    int step = 0;

    cout << "\nInitial Tape: " << tape << endl << endl;

    // Perform transitions
    while (true) {
        step++;
        if (currentState == "q0") {
            if (tape[head] == '1') {
                tape[head] = '0';
                printStep(step, tape, head, currentState, "q0");
                head--; // Move left
            } else if (tape[head] == '0') {
                tape[head] = '1';
                printStep(step, tape, head, currentState, "qf");
                break; // Halt
            } else if (tape[head] == ' ') {
                tape.insert(tape.begin(), '1'); // Prepend '1' for overflow
                printStep(step, tape, head, currentState, "qf");
                break; // Halt
            }
        }
    }

    // Print final tape
    cout << "\nFinal Tape: " << tape << endl;
}

int main() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;

    incrementBinary(binary);

    return 0;
}
