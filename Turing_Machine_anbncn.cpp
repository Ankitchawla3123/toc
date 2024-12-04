#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the current tape and state details
void printStep(int step, const string& tape, int head, const string& currentState, const string& nextState) {
    cout << "Step: " << step << " | Tape: " << tape << " | Head: " << head
         << " | Current State: " << currentState << " -> Next State: " << nextState << endl;
}

// Turing Machine simulation for a^n b^n c^n
void checkAnBnCn(string input) {
    // Initialize tape, head, and state
    string tape = input + " "; // Add blank space at the end of tape
    int head = 0;              // Start at the beginning of the tape
    string currentState = "q0";
    int step = 0;

    cout << "\nInitial Tape: " << tape << endl << endl;

    // Perform transitions
    while (true) {
        step++;
        if (currentState == "q0") {
            if (tape[head] == 'a') {
                tape[head] = 'X'; // Mark 'a' as processed
                printStep(step, tape, head, currentState, "q1");
                currentState = "q1";
                head++; // Move right
            } else if (tape[head] == ' ') {
                printStep(step, tape, head, currentState, "qAccept");
                break; // Accept the string if all conditions are met
            } else {
                printStep(step, tape, head, currentState, "qReject");
                cout << "\nString rejected: Incorrect order or unmatched counts.\n";
                return; // Reject the string
            }
        } else if (currentState == "q1") {
            if (tape[head] == 'a') {
                head++; // Skip over remaining 'a's
            } else if (tape[head] == 'b') {
                tape[head] = 'Y'; // Mark 'b' as processed
                printStep(step, tape, head, currentState, "q2");
                currentState = "q2";
                head++; // Move right
            } else {
                printStep(step, tape, head, currentState, "qReject");
                cout << "\nString rejected: Incorrect order or unmatched counts.\n";
                return; // Reject the string
            }
        } else if (currentState == "q2") {
            if (tape[head] == 'b') {
                head++; // Skip over remaining 'b's
            } else if (tape[head] == 'c') {
                tape[head] = 'Z'; // Mark 'c' as processed
                printStep(step, tape, head, currentState, "q3");
                currentState = "q3";
                head--; // Move left
            } else {
                printStep(step, tape, head, currentState, "qReject");
                cout << "\nString rejected: Incorrect order or unmatched counts.\n";
                return; // Reject the string
            }
        } else if (currentState == "q3") {
            if (tape[head] == 'b' || tape[head] == 'Y') {
                head--; // Move left over 'b's and processed markers
            } else if (tape[head] == 'a' || tape[head] == 'X') {
                head--; // Move left over 'a's and processed markers
            } else if (tape[head] == ' ') {
                printStep(step, tape, head, currentState, "q0");
                currentState = "q0"; // Restart for the next cycle
                head++; // Move right
            }
        }
    }

    // Check if all symbols are marked
    for (char c : tape) {
        if (c != 'X' && c != 'Y' && c != 'Z' && c != ' ') {
            cout << "\nString rejected: Not all symbols are processed.\n";
            return;
        }
    }

    // If the tape is fully processed and no issues found
    cout << "\nString accepted: The input is a valid a^n b^n c^n.\n";
}

int main() {
    string input;
    cout << "\nEnter a string (a^n b^n c^n): ";
    cin >> input;

    checkAnBnCn(input);

    return 0;
}
