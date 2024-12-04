#include <iostream>
#include <string>
using namespace std;

void state0(const string &w, int i);
void state1(const string &w, int i);
void state2(const string &w, int i);
void state3(const string &w, int i);
void stateTrap(const string &w, int i);

void simulateFA(const string &w) {
    state0(w, 0);
}

void state0(const string &w, int i) {
    if (i == w.length()) {
        cout << "String is rejected" << endl;
        return;
    }
    cout << "State 0, Character: " << w[i] << endl;
    if (w[i] == '0') {
        state0(w, i + 1);
    } else if (w[i] == '1') {
        state1(w, i + 1);
    } else {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void state1(const string &w, int i) {
    if (i == w.length()) {
        cout << "String is rejected" << endl;
        return;
    }
    cout << "State 1, Character: " << w[i] << endl;
    if (w[i] == '0') {
        state1(w, i + 1);
    } else if (w[i] == '1') {
        state2(w, i + 1);
    } else {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void state2(const string &w, int i) {
    if (i == w.length()) {
        cout << "String is accepted (exactly two 1's)" << endl;
        return;
    }
    cout << "State 2, Character: " << w[i] << endl;
    if (w[i] == '0') {
        state2(w, i + 1);
    } else if (w[i] == '1') {
        state3(w, i + 1);
    } else {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void state3(const string &w, int i) {
    if (i == w.length()) {
        cout << "String is accepted (exactly three 1's)" << endl;
        return;
    }
    cout << "State 3, Character: " << w[i] << endl;
    if (w[i] == '0') {
        state3(w, i + 1);
    } else if (w[i] == '1') {
        stateTrap(w, i + 1);
    } else {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void stateTrap(const string &w, int i) {
    if (i == w.length()) {
        cout << "String is rejected" << endl;
        return;
    }
    cout << "Trap State, Character: " << w[i] << endl;
    stateTrap(w, i + 1);
}

int main() {
    string input;
    cout << "Enter a binary string (containing only 0's and 1's): ";
    cin >> input;
    simulateFA(input);
    return 0;
}
