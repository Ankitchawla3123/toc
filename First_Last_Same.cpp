#include <iostream>
#include <string>
using namespace std;

void state0(const string &w, int i); // Starting state
void state1(const string &w, int i, char first1, char first2); // To check first two characters
void state2(const string &w, int i, char first1, char first2); // To check last two characters

void simulateFA(const string &w)
{
    if (w.length() < 4)
    {
        cout << "String is rejected (Length is less than 4)" << endl;
        return;
    }
    state0(w, 0);
}

void state0(const string &w, int i)
{
    // Start reading first two characters
    cout << "State 0: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b')
    {
        cout << "Invalid character encountered. String is rejected." << endl;
        return;
    }
    state1(w, i + 1, w[i], w[i + 1]); // Proceed to state1 with the first two characters
}

void state1(const string &w, int i, char first1, char first2)
{
    cout << "State 1: Reading '" << w[i] << "'" << endl;
    if (w[i] != 'a' && w[i] != 'b')
    {
        cout << "Invalid character encountered. String is rejected." << endl;
        return;
    }
    if (i >= w.length() - 2)
    {
        // Move to state2 when we reach the last two characters
        state2(w, i, first1, first2);
    }
    else
    {
        // Keep reading in state1 until we are at the last two characters
        state1(w, i + 1, first1, first2);
    }
}

void state2(const string &w, int i, char first1, char first2)
{
    cout << "State 2: Checking last two characters" << endl;
    // Compare last two characters with first two
    if (w[i] == first1 && w[i + 1] == first2)
    {
        cout << "String is accepted (First two characters match last two)" << endl;
    }
    else
    {
        cout << "String is rejected (First two characters do not match last two)" << endl;
    }
}

int main()
{
    string input;
    cout << endl << "Enter a string over {a, b}: ";
    cin >> input;
    simulateFA(input);
    return 0;
}
