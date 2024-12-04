#include <iostream>
#include <string>
using namespace std;

void state0(const string &w, int i);
void state1(const string &w, int i);
void state2(const string &w, int i);

void simulateFA(const string &w)
{
    state0(w, 0);
}

void state0(const string &w, int i)
{
    cout << "State 0: Reading '" << w[i] << "'" << endl;
    if (i == w.length())
    {
        cout << "String is rejected" << endl;
        return;
    }
    if (w[i] == 'a')
    {
        state1(w, i + 1);
    }
    else
    {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void state1(const string &w, int i)
{
    cout << "State 1: Reading '" << w[i] << "'" << endl;
    if (i == w.length())
    {
        cout << "String is rejected" << endl;
        return;
    }
    if (w[i] == 'a')
    {
        state1(w, i + 1);
    }
    else if (w[i] == 'b')
    {
        state2(w, i + 1);
    }
    else
    {
        cout << "Invalid character encountered. String is rejected." << endl;
    }
}

void state2(const string &w, int i)
{
    cout << "State 2: Reading '" << w[i] << "'" << endl;

    if (i == w.length())
    {
        cout << "String is accepted" << endl;
        return;
    }

    if (w[i] == 'b')
    {
        state2(w, i + 1);
        if (i + 1 == w.length())
        {
            cout << "String is accepted" << endl;
            return;
        }
    }
    else if (w[i] == 'a')
    {
        state1(w, i + 1);
    }
}

int main()
{
    string input;
    cout << "Enter a string (containing only 'a' and 'b'): ";
    cin >> input;
    simulateFA(input);
    return 0;
}
