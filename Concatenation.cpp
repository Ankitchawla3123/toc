#include <iostream>
#include <string>
using namespace std;

// Prototypes for state functions
void stateL1_0(const string &w, int i); // Start state for L1
void stateL1_1(const string &w, int i, char first1, char first2); // Check first two characters
void stateL1_2(const string &w, int i, char first1, char first2); // Check last two characters

void stateL2_0(const string &w, int i); // Start state for L2

void simulateFA(const string &w); // Simulate the concatenated FA

// Function to simulate the concatenated FA
void simulateFA(const string &w) {
    if (w.length() < 4) {
        cout << "String is rejected (Length is less than 4)" << endl;
        return;
    }

    // Start simulating both FAs
    stateL1_0(w, 0); // Start L1 FA
    stateL2_0(w, 0); // Start L2 FA
}

// L1 simulation: First two characters should match last two
void stateL1_0(const string &w, int i) {
    cout << "L1 State 0: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b') {
        cout << "Invalid character encountered in L1. String is rejected." << endl;
        return;
    }
    stateL1_1(w, i + 1, w[i], w[i + 1]); // Move to next state
}

void stateL1_1(const string &w, int i, char first1, char first2) {
    cout << "L1 State 1: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b') {
        cout << "Invalid character encountered in L1. String is rejected." << endl;
        return;
    }
    if (i >= w.length() - 2) {
        stateL1_2(w, i, first1, first2); // Move to last two characters
    } else {
        stateL1_1(w, i + 1, first1, first2); // Continue reading
    }
}

void stateL1_2(const string &w, int i, char first1, char first2) {
    cout << "L1 State 2: Checking last two characters" << endl;
    if (w[i] == first1 && w[i + 1] == first2) {
        cout << "String is accepted by L1 (First two characters match last two)" << endl;
    } else {
        cout << "String is rejected by L1 (First two characters do not match last two)" << endl;
    }
}

// L2 simulation: Alternating 'a' and 'b' for exactly 4 characters
void stateL2_0(const string &w, int i) {
    cout << "L2 State 0: Reading '" << w[i] << "'" << endl;
    if (w.length() == 4 && w[0] != w[1] && w[1] != w[2] && w[2] != w[3]) {
        cout << "String is accepted by L2 (Alternating characters 'abab' or 'baba')" << endl;
    } else {
        cout << "String is rejected by L2" << endl;
    }
}

int main() {
    string input;
    cout << endl << "Enter a string over {a, b}: ";
    cin >> input;
    simulateFA(input);
    return 0;
}
