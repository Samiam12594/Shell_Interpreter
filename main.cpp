#include <filesystem>
#include <iostream>
using namespace std;

//version 0.0.1
int main() {
    cout << "Hello and welcome to Sam's Shell interpreter!\n";
    string input;

    while (true) {
        string current_path = filesystem::current_path();
        cout << "~ " << current_path.substr(current_path.find_last_of("/") + 1) << " >> ";
        cin >> input;
        cout << "You have select: " << input << "\n";
        if (input == "exit") {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
