
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "CharSheet.h"

using namespace std;

void showCharacterList(vector<CharSheet> &);
void deleteCharacter(vector<CharSheet> &);

int main() {
    
    // Initializing the seed for rand
    srand(time(NULL));
    
    // Vector to hold all the character sheets
    vector<CharSheet> chlist;
    
    // Variable to show when to end the main loop
    bool cont = true;
    
    // Variable for storing user commands
    string opt;
    
    cout << "Hello! Welcome to Character Builder!\n";
    cout << endl;
    
    cout << "Start?";
    getline(cin, opt);
    
    // Loop until quit
    while (cont) {
        
        opt = "";
        
        // Showing options
        cout << "\nWhat do you want to do?" << endl << 
                "(N)ew Character      (R)andom New Character" << endl <<
                "(S)how Characters    (D)elete" << endl
                << "(Q)uit" << endl;
    
        
        // Read command
        getline(cin, opt);
        
        // Quit
        if (opt == "q" || opt == "Q") {
            cout << endl << "Farewell!" << endl << endl;
            cont = false;
        }
        
        // New character
        else if (opt == "n" || opt == "N") {
            
            // Create without randomizing
            chlist.push_back(CharSheet(false));
            // Print
            chlist.back().printCharacter();
            
        }
        
        
        // New random character
        else if (opt == "r" || opt == "R") {
            
            // Create with full randomization and print
            chlist.push_back(CharSheet(true));
            chlist.back().printCharacter();
        }
        
        
        // Show character list
        else if (opt == "s" || opt == "S") {
            
            showCharacterList(chlist);
            
        }
        
        // Delete character
        else if (opt == "d" || opt == "D") {
        
            deleteCharacter(chlist);
        
        }
    }
    
    return 0;
}

// Walks the user through the character deletion process
void deleteCharacter(vector<CharSheet> &chlist) {
    
    // If character vector is empty, there's nothing to delete
    if (chlist.size() == 0) {
        cout << endl << "No characters to delete." << endl;
    }
    
    else {
        
        string del; // user's choice variable
        bool success = false; // valid command?
        
        while (!success) {

            cout << endl << "Which character would you like to delete?" 
                 << endl;

            // Give simplified list of characters to choose from
            for (int i = 0; i < chlist.size(); i++) {
                cout << "(" << i+1 << ") " << chlist.at(i).getName() <<
                        ", " << chlist.at(i).getRace() << " " << 
                        chlist.at(i).getClass() << endl;
            }
            cout << "Or (C)ancel." << endl;

            // Read user seleciton
            getline(cin, del);
            
            // Cancel
            if (del == "c" || del == "C") {
                success = true;
            }
            // Else try to find character based on index given
            else {
                for (int j = 0; j < chlist.size(); j++) {
                    
                    // When index is found, delete character and break loop
                    if (del == to_string(j+1)) {

                        chlist.erase(chlist.begin() + j);

                        cout << endl << "Deleted." << endl;
                        success = true;
                        break;
                    }
                }
                // If index was not found, print error
                if (!success) {
                    cout << endl << "Character not found." << endl;
                }
            }
        }
    }
}

// Prints out list of all stored characters
void showCharacterList(vector<CharSheet> &chlist) {
    
    // Use class's own print function to print each character
    for (int i = 0; i < chlist.size(); i++) {
        chlist.at(i).printCharacter();
    }
    // How many characters in total
    cout << endl << chlist.size() << " character(s) in total." << endl;
}