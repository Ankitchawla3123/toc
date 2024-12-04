#include <iostream>
#include <string>
using namespace std;

string tape;
int head_position;
string state = "q0";

void print_tape() {
    cout << tape << endl;
}

bool move_head(char direction) {
    if (direction == 'R') {
        if (head_position < tape.size() - 1) {
            head_position++;
            return true;
        }
    } else if (direction == 'L') {
        if (head_position > 0) {
            head_position--;
            return true;
        }
    }
    return false;
}

bool TuringMachine(string input) {
    tape = input;
    head_position = 0;

    print_tape();

    while (true) {
        char current_symbol = tape[head_position];
        
        if (state == "q0") {
            if (current_symbol == 'a') {
                tape[head_position] = 'X'; // Mark 'a'
                move_head('R');
                state = "q1";
            } else {
                return false; // Invalid input (no 'a' found)
            }
        } else if (state == "q1") {
            if (current_symbol == 'b') {
                tape[head_position] = 'Y'; // Mark 'b'
                move_head('R');
                state = "q2";
            } else {
                return false; // Invalid input (no 'b' found)
            }
        } else if (state == "q2") {
            if (current_symbol == 'c') {
                tape[head_position] = 'Z'; // Mark 'c'
                move_head('L');
                state = "q3";
            } else {
                return false; // Invalid input (no 'c' found)
            }
        } else if (state == "q3") {
            if (current_symbol == 'X') {
                move_head('R');
                state = "q0";
            } else if (current_symbol == 'Y') {
                move_head('R');
                state = "q1";
            } else if (current_symbol == 'Z') {
                move_head('R');
                state = "q2";
            } else {
                return false; // No more symbols to process
            }
        }

        // Print tape and state at each step
        cout << "State: " << state << ", Tape: ";
        print_tape();
        
        // Check if input is valid (all marked, no unprocessed symbols)
        if (tape.find('a') == string::npos && tape.find('b') == string::npos && tape.find('c') == string::npos) {
            cout << "Input accepted!" << endl;
            return true;
        }
    }

    return false;
}

int main() {
    string input;
    cout << "Enter input string (only a's, b's, and c's in order): ";
    cin >> input;
    
    // Check if input follows the correct format
    if (input.empty() || input.find_first_not_of("abc") != string::npos) {
        cout << "Invalid input format!" << endl;
        return 0;
    }
    
    // Simulate the Turing machine
    if (TuringMachine(input)) {
        cout << "String accepted by the Turing machine." << endl;
    } else {
        cout << "String rejected by the Turing machine." << endl;
    }
    
    return 0;
}
