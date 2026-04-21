// Brian Foster Coding 1b week 14a
// Writing to and reading from files.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>          // file stream

using namespace std;


void read(string path = "save.txt") {
    // create a new var, and try to open a file
    string line;
    ifstream readFile(path);              // input file stream
    if(readFile.is_open()) {
        // cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        // cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it!!
    readFile.close();
}

// overloaded function name.
void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        // cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);            // add each line to the vector.
        }
    }
    else {
        // cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it!!
    readFile.close();
}

void write(vector<string>& vec, string path = "save.txt") {
    // cout << "starting write() function.\n";
    ofstream writeFile(path);

    if(writeFile.is_open()) {
        // cout << "the write file is open.\n";
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    } 
    else {
        cout << "Couldn't open new writeFile.\n";
    }

    writeFile.close();
    // cout << "end of write() function.\n";
}

void show(vector<string>& vec) {
    cout << "\nHere are the elements in your vector:\n\n";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}


int main(int argc, char* argv[]) {
    bool debug = false;
    // if(*(argv[1]) == 1) debug = true;

    
    if(debug) {
        cout << "DEBUG MODE IS ACTIVE\n";
    }
    
    cout << "Let's write to a file!\n";
    vector<string> favs;
    string input = "asdf";

    string path = "save.txt";

    cout << "What file would you like to open?\ntype 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input + ".txt";       // this let's us open different files!!!
    }


    show(favs);             // show the current names
    read(favs, path);         // add the names to the vector

    if(favs.empty()) {
        cout << "That's a new file.\n";
    }

    cout << "What names would you like to add?\n";
    cout << "enter an empty line to stop.\n";
          
    while(true) {
        cout << "> ";
        getline(cin, input);

        if(input == "") break;
        else favs.push_back(input);
    }

    // now call the write function and send it our favs vector.
    write(favs, path);


    return 0;
}