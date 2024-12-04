#include <iostream>
#include <string>
using namespace std;

// Prototypes for state functions for L1 and L2 DFAs
void stateL1_0(const string &w, int i, char first1, char first2);  // Start state for L1
void stateL1_1(const string &w, int i, char first1, char first2);  // L1 state for checking first two characters
void stateL1_2(const string &w, int i, char first1, char first2);  // L1 state for checking last two characters
void stateL2_0(const string &w, int i);  // Start state for L2
void simulateIntersectionFA(const string &w);  // Function to simulate the intersection FA

// Function to simulate the intersection of L1 and L2
void simulateIntersectionFA(const string &w) {
    if (w.length() < 4) {
        cout << "String is rejected (Length is less than 4)" << endl;
        return;
    }
    // Start simulating both FAs in parallel
    stateL1_0(w, 0, w[0], w[1]);  // Start L1 FA
    stateL2_0(w, 0);  // Start L2 FA
}

// L1 simulation (first two characters should match last two)
void stateL1_0(const string &w, int i, char first1, char first2) {
    cout << "L1 State 0: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b') {
        cout << "Invalid character encountered in L1. String is rejected." << endl;
        return;
    }
    stateL1_1(w, i + 1, first1, first2);  // Move to the next state
}

void stateL1_1(const string &w, int i, char first1, char first2) {
    cout << "L1 State 1: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b') {
        cout << "Invalid character encountered in L1. String is rejected." << endl;
        return;
    }
    if (i >= w.length() - 2) {
        stateL1_2(w, i, first1, first2);  // Check the last two characters in stateL1_2
    } else {
        stateL1_1(w, i + 1, first1, first2);  // Continue reading the string
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

// L2 simulation (for simplicity, we assume L2 accepts strings where the first and last characters match)
void stateL2_0(const string &w, int i) {
    cout << "L2 State 0: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b') {
        cout << "Invalid character encountered in L2. String is rejected." << endl;
        return;
    }
    // For simplicity, check if string starts and ends with the same character (basic L2 example)
    if (i == w.length() - 1 && w[0] == w[i]) {
        cout << "String is accepted by L2 (First and last characters match)" << endl;
    } else {
        cout << "String is rejected by L2" << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;
    simulateIntersectionFA(input);  // Simulate the intersection DFA
    return 0;
}
