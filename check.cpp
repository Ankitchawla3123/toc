#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TuringMachine {
public:
    TuringMachine() {
        // Initialize the tape and head
        tape = vector<char>(1000, ' '); // 1000 cells on the tape
        head = 500; // Start at the middle of the tape
        currentState = "q0";
    }

    void run(const string& input) {
        // Load the input onto the tape
        for (int i = 0; i < input.length(); i++) {
            tape[head + i] = input[i];
        }

        // Run the Turing machine
        while (true) {
            // Display the current state and tape
            cout << "Current state: " << currentState << " Head at position: " << head << " Tape: ";
            // cout<<tape[head];
            for (int i = head - 6; i <= head + 6; i++) {
                cout << tape[i];
            }
            cout << endl;

            // Process based on the current state and tape symbol
            if (currentState == "q0") {
                if (tape[head] == 'a') {
                    tape[head] = 'X'; // Mark 'a' as 'X'
                    head++; // Move right
                    currentState = "q1";
                } else if (tape[head] == 'X') {
                    currentState = "q0"; // If no more 'a's, check for empty input
                    head++;
                } 
                else if (tape[head] == 'Y') {
                    currentState = "q1"; // If no more 'a's, check for empty input
                } 
                else if (tape[head] == 'Z')
                {
                    
                }
                
                else {
                    break; // Halt if neither 'a' nor blank space
                }
            } else if (currentState == "q1") {
                if (tape[head] == 'a' || tape[head] == 'Y'  ) {
                    head++; // Move right to continue looking for the first 'b'
                } else if (tape[head] == 'b') {
                    tape[head] = 'Y'; // Mark 'b' as 'Y'
                    head++; // Move right
                    currentState = "q2";
                } else {
                    break; // Halt if no 'b' found
                }
            } else if (currentState == "q2") {
                if (tape[head] == 'b' || tape[head]=='Z') {
                    head++; // Move right
                } else if (tape[head] == 'c') {
                    tape[head] = 'Z'; // Mark 'c' as 'Z'
                    head--; // Move left
                    currentState = "q3";
                } else {
                    break; // Halt if no 'c' found
                }
            } else if (currentState == "q3") {
                if (tape[head] == 'X') {
                 // Move left to find the next unmarked 'a'
                    currentState = "q0"; // Go back to q0 to mark the next 'a'
                } else if (tape[head] == 'Y' || tape[head] == 'Z') {
                    head--; // Move left
                    currentState = "q3"; // If no unmarked 'a' left, check for all 'Y'

                } 
                else if (tape[head] == 'b')
                {
                    head--;
                    currentState = "q3";
                }
                else if (tape[head] == 'a')
                {
                    head--;
                    currentState = "q3";
                }
        
                
                else {
                    break; // Halt if neither 'X' nor 'Y' found
                }
            } else if (currentState == "q4") {
                if (tape[head] == 'Y') {
                    head--; // Move left to continue checking 'Y'
                    currentState = "q4"; // Continue until no more 'Y'
                } else if (tape[head] == 'Z') {
                    head--; // Move left to continue checking 'Z'
                    currentState = "qf"; // Final state
                } else {
                    break; // Halt if no 'Y' or 'Z' found
                }
            } else if (currentState == "qf") {
                // Final state, halt the machine
                cout << "Machine halts at final state." << endl;
                break;
            } else {
                break; // Halt if an unknown state is encountered
            }
        }
    }

private:
    vector<char> tape;  // The tape
    int head;           // The head position
    string currentState; // The current state
};

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    TuringMachine tm;
    tm.run(input); // Run the Turing machine

    return 0;
}
