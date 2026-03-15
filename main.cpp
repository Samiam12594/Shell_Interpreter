#include <iostream>
using namespace std;

//version 0.0.1
int main() {
    cout << "Hello and welcome to Sam's Shell interpreter!\n";
    string input;

    while (true) {
        cout << "> ";
        cin >> input;
        cout << "You have select: " << input << "\n";
        if (input == "exit") {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}