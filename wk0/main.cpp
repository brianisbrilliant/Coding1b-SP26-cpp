// Brian Foster Coding 1 Spring 2026
// My first C++ Program

// to compile, open the 'Developer Command Prompt for VS 2022'
// navigate to this folder with 'cd' for 'changed directory'
// use the command 'cl /EHsc filename.cpp' (in this case, it's 'main.cpp')
// and then type 'filename' to run the .exe (in this case, it's 'main')


#include <iostream>         // in out stream, for sending text to the console.
#include <string>           // for playerName

using namespace std;        // so we don't have to type "std::" all the time.

// here is where we start the program
int main() {
    // variables declared at the top is best practice.
    string playerName;      // variables use camelCase

    // ask the player for their name
    cout << "What is your name, player? ";

    // assign whatever the player types as the value of playerName
    cin >> playerName;
    
    // greet the player by name
    cout << "Hello " << playerName << "." << endl;
    
    // user Control+slash to comment out lines.
    // cout << "Hello World!" << endl;         // cout = console out, endl = end line

    return 0;               // end the program
}