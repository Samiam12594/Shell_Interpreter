#include <filesystem>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

//version 0.0.2

/*
 * Function returns full line that user
 * inputted and breaks each string up into
 * distinct elements
 * eg: string input: echo hello world
 * parser(input) = {"echo", "hello", "world"}
 */
vector<string> parser(string s) {
    //stringstream enables us to extract data from other data,
    //in this case individual string(s) from string(s) with white spaces
    stringstream full_command(s);
    //create vector that will contain individual string(s) extracted
    vector<string> inputParsed;
    //creating empty string that we will use to extract individual string(s) from s
    string word;

    //while full_command has string extractable from it
    //add to inputParsed vector

    /*
     * EG: stringstream full_command = "echo hello world"
     * iteration 1: full_command >> word = "echo" = true
     * inputParsed.push_back(word) = {"echo"}
     * continue
     * iteration 2: full_command >> word = "hello" = true
     * inputParsed.push_back(word) = {"echo", "hello"}
     * iteration 3: full_command >> word = "world" = true
     * inputParsed.push_back(word) = {"echo", "hello", "world}
     * continue
     * iteration 4: full_command >> word = (stream empty) = false
     * break
     */
    while (full_command >> word) {
        inputParsed.push_back(word);
    }
    return inputParsed;
}


/*
 * Method allows the program to know via
 * preprocessor directives
 */
void clearScreen() {
    //preprocessor if platform is windows uses windows specific command to clear terminal
#ifdef _WIN32
    std::system("cls"); // For Windows
    //preprocessor else if platform is Linus OR Mac uses "clear" as both work to clear the terminal
#elif defined(__unix__) || defined(__APPLE__)
    std::system("clear"); // For Linux and macOS (Unix-like systems)
    //preprocessor else prints 50 empty lines to act as a faux "clear"
#else
    // Fallback for unsupported systems, or do nothing
    std::cout << std::string(50, '\n'); // Print newlines as a simple fallback
#endif
}

//function that replaces the input string for if
//statements in main to check if a given command is in the vector
//by using the find method
bool contains_word(vector<string> h, string s) {

    //using all of to check if atr at any point equals the desired number
    // false case: h = {"exit", "hello", "world"}, s = "exit"
    // iteration 1: str = "exit", str == s = true
    // iteration 2: str = "hello", str != s = false
    // iteration 3: since false condition was met, all_of returns false, no unneccesary checks;
    // true case: h = {"exit"}, s = "exit"
    // iteration 1: str = "exit", str == s = true
    // iteration 2: no more values in the array, all_of returns true;
    return all_of(h.begin(), h.end(), [&](const string& str) {
        return str == s;
    });

}

int main() {
    cout << "Hello and welcome to Sam's Shell interpreter!\n";
    string input;

    while (true) {
        //cp will be the current directory that user is in
        string cp = filesystem::current_path();
        //using erase(remove()) function to get rid of quotations as current_path returns it as a string wrapped in quotations
        cp.erase(remove(cp.begin(), cp.end(), '"'), cp.end());
        //display cp as current directory
        cout << "~ " << cp << " >> ";
        //get entire line, cin just gets the first string until interrupted by whitespace
        getline(cin, input);
        //creating vector that holds each command string for later execution
        vector<string> inputParsed = parser(input);


        //Testing if parsing worked properly
        /*
        for (auto i : inputParsed) {
            cout << i << endl;
        }
*/
        /*
         * Testing input string
         */

        //cout << "You have select: " << input << "\n";

        /*put two if statements here to demonstrate basic functionality*/

        if (contains_word(inputParsed, "clear")) {
            clearScreen();
        }
        if (contains_word(inputParsed, "exit")) {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
