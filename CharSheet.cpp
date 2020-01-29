
#include "CharSheet.h"
#include <iostream>

using namespace std;

// Names of the stats
const string STATS_NAMES[] = { "Strength", "Agility", "Intellect", "Charisma" };


// Default constructor, builds a fully random character sheet
CharSheet::CharSheet() {
    c_name = generateName(true);
    c_race = generateRace(true);
    c_class = generateClass(true);
    c_gender = generateGender(true);
    setStats(true);
}

/* Constructor for when you want to directly assign all the values */
CharSheet::CharSheet(string name, string race, string cclass, int gender,
                     int stats[STATS_COUNT]) {
    c_name = name;
    c_race = race;
    c_class = cclass;
    c_gender = gender;
    
    for (int i = 0; i < STATS_COUNT; i++) {
        c_stats[i] = stats[i];
    }
}

/* Constructor for generating a new character where all stats are generated 
   either randomly or manually, as determined by the parameter */
CharSheet::CharSheet(bool randomSheet) {
    c_name = generateName(randomSheet);
    c_race = generateRace(randomSheet);
    c_class = generateClass(randomSheet);
    c_gender = generateGender(randomSheet);
    setStats(randomSheet);
}

/* Constructor for generating a new character sheet where the parameters
   determine which variables are to be generated randomly */
CharSheet::CharSheet(bool randomName, bool randomRace, 
                     bool randomClass, bool randomGender, bool randomStats) {
    
    c_name = generateName(randomName);
    c_race = generateRace(randomRace);
    c_class = generateClass(randomClass);
    c_gender = generateGender(randomGender);
    setStats(randomStats);
}

// Copy constructor
CharSheet::CharSheet (const CharSheet &old) {
    c_name = old.c_name;
    c_race = old.c_race;
    c_class = old.c_class;
    c_gender = old.c_gender;
    
    for (int i = 0; i < STATS_COUNT; i++) {
        c_stats[i] = old.c_stats[i];
    }
    
}



/* Generates character's name
   Parameter determines whether the value is determined randomly or
   through user input */
string CharSheet::generateName(bool random) {
    
    // Random
    if (random) {
        return generateRandomName();
    }
    
    // User input
    string name = "";
    cout << "\n*** New Character ***" << endl;
    while (name == "") {
        
        cout << "\nWhat is your character's name?" << endl;
        cout << "Examples: ";
        
        // Generate a few random example names
        for (int i = 0; i < 5; i++) {
            cout << generateRandomName() << " ";
        }
        cout << endl;
        
        // Ask for user input
        cout << "Name: ";
        getline(cin, name);
    }
    
    return name;
    
}

/* Generates a random-ish five-letter name */
string CharSheet::generateRandomName() {
    
    string name = "";
    
    const char UPPER_CASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char VOWELS[] = "aeiouy";
    const char CONSONANTS[] = "bcdfghjklmnpqrstvwxz";
    //const char LOWER_CASE_ALL[] = "abcdefghijklmnopqrstuvwxyz";
    
    // First letter can be any letter
    name += UPPER_CASE[rand() % strlen(UPPER_CASE)];
    // then vowel-consonant-vowel
    name += VOWELS[rand() % strlen(VOWELS)];
    name += CONSONANTS[rand() % strlen(CONSONANTS)];
    name += VOWELS[rand() % strlen(VOWELS)];
    // finally 50/50 chance to get a vowel vs. a consonant as the last letter
    if (rand()%2 == 1)
        name += VOWELS[rand() % strlen(VOWELS)];
    else
        name += CONSONANTS[rand() % strlen(CONSONANTS)];
    
    
    return name;
    
}

/* Generates character's race
   Parameter determines whether the value is determined randomly or 
   through user input */
string CharSheet::generateRace(bool random) {
    
    // Default races
    const string RACE1 = "human";
    const string RACE2 = "orc";
    const string RACE3 = "elf";
    const string RACE4 = "dwarf";
    const string RACE5 = "halfling";
    
    string yourRace = "";
    
    // Choose a random race index from the defaults
    if (random) {
            int randomRace = rand() % 5 + 1;
            yourRace = to_string(randomRace);
    }
    
    // Otherwise ask the user
    while (yourRace == "") {
        
        cout << endl;
        cout << "Choose your race:\n";
        cout << "(1) " << RACE1 << endl;
        cout << "(2) " << RACE2 << endl;
        cout << "(3) " << RACE3 << endl;
        cout << "(4) " << RACE4 << endl;
        cout << "(5) " << RACE5 << endl;
        cout << "Or type in your own." << endl;
        cout << "Race: ";
    
        getline(cin, yourRace);
        
    }
    
    // Convert index to race
    if (yourRace == "1")
        return RACE1;
    else if (yourRace == "2")
        return RACE2;
    else if (yourRace == "3")
        return RACE3;
    else if (yourRace == "4")
        return RACE4;
    else if (yourRace == "5")
        return RACE5;
    else
        return yourRace;
    
}

/* Generates character's gender
   Parameter determines whether the value is determined randomly or 
   through user input */
string CharSheet::generateGender(bool random) {
    
    const string GENDER1 = "male";
    const string GENDER2 = "female";
    const string GENDER3 = "genderless";
    
    string yourGender = "";
    
    while (true) {
        
        // Random
        if (random) {
            int randomGender = rand() % 4 + 1;
            yourGender = to_string(randomGender);
        }
        
        // User input
        else {
            
            cout << endl;
            cout << "Choose your gender:\n";
            cout << "(1) " << GENDER1 << endl;
            cout << "(2) " << GENDER2 << endl;
            cout << "(3) " << GENDER3 << endl;
            cout << "Gender: ";
            
            getline(cin, yourGender);
            
        }
            // Convert index to text
            if (yourGender == "1")
                return GENDER1;
            else if (yourGender == "2")
                return GENDER2;
            else if (yourGender == "3")
                return GENDER3;
        
    }
    
    
}

/* Generates character's class
   Parameter determines whether the value is determined randomly or 
   through user input */
string CharSheet::generateClass(bool random) {
    
    const string CLASS1 = "warrior";
    const string CLASS2 = "sorcerer";
    const string CLASS3 = "rogue";
    const string CLASS4 = "ranger";
    const string CLASS5 = "cleric";
    const string CLASS6 = "druid";
    const string CLASS7 = "bard";
    
    string yourClass = "";
    
    // Random
    if (random) {
            int randomClass = rand() % 7 + 1;
            yourClass = to_string(randomClass);
    }
    
    // User
    else {
    
        while (yourClass == "") {
            cout << endl;
            cout << "Choose your class:\n";
            cout << "(1) " << CLASS1 << endl;
            cout << "(2) " << CLASS2 << endl;
            cout << "(3) " << CLASS3 << endl;
            cout << "(4) " << CLASS4 << endl;
            cout << "(5) " << CLASS5 << endl;
            cout << "(6) " << CLASS6 << endl;
            cout << "(7) " << CLASS7 << endl;
            cout << "Or type in your own." << endl;
            cout << "Class: ";

            getline(cin, yourClass);

        }
    }
    
    // Convert index to text
    if (yourClass == "1")
        return CLASS1;
    else if (yourClass == "2")
        return CLASS2;
    else if (yourClass == "3")
        return CLASS3;
    else if (yourClass == "4")
        return CLASS4;
    else if (yourClass == "5")
        return CLASS5;
    else if (yourClass == "6")
        return CLASS6;
    else if (yourClass == "7")
        return CLASS7;
    else
        return yourClass;
    
}

/* Getters */

string CharSheet::getName() {
    return c_name;
}

string CharSheet::getRace() {
    return c_race;
}
string CharSheet::getGender() {
    return c_gender;
}
string CharSheet::getClass() {
    return c_class;
}

vector<int> CharSheet::getStats() {
    
    vector<int> stats;
    
    for (int i = 0; i < STATS_COUNT; i++) {
        stats.push_back(stats[i]);
    }
    
    return stats;
}

/* Setters */

void CharSheet::setName(string name) {
    c_name = name;
}

void CharSheet::setRace(string race) {
    c_race = race;
}
void CharSheet::setGender(string gender) {
    c_gender = gender;
}
void CharSheet::setClass(string cclass) {
    c_class = cclass;
}

// Allocates stat points
void CharSheet::setStats(bool random) {
    
    // Initialize to zero just in case?
    for (int i = 0; i < STATS_COUNT; i++) {
        c_stats[i] = 0;
    }
    
    int statPointsLeft = MAX_STAT_POINTS;
    
    // Ask the user (continue asking until out of points or random is chosen
    while (!random && statPointsLeft > 0) {
        
        string choice = "";
        
        cout << "\n*** Character stats ***" << endl;
        cout << "You have " << statPointsLeft << " stat point(s) left. "
                << "Where do you want to put the next one?" << endl;
        for (int x = 0; x < STATS_COUNT; x++) {
            cout << "(" << x+1 << ") " << STATS_NAMES[x] << ": " << c_stats[x] << endl;
        }
        cout << "Or (r) to allocate the rest randomly." << endl;
        
        getline(cin, choice);
        
        if (choice == "r") {
            random = true;
        }
        else {
            // Attempt to match user input with a stat index
            for (int y = 0; y < STATS_COUNT; y++) {
                
                // If successful, allocate point to that stat and end loop
                if (choice == to_string(y+1)) {
                    c_stats[y]++;     // add point to stat
                    statPointsLeft--; // remove point from total
                    y = STATS_COUNT;  // end loop
                }
            }
        }
    }
    
    // Allocate (remaining) stats randomly
    if (random) {
        // Assign each point to random stat
        for (int j = 0; j < statPointsLeft; j++) {
            int index = rand()%STATS_COUNT;
            c_stats[index]++;
        }
    }
    
}

// Prints character's name, gender, race, class, and stats
void CharSheet::printCharacter() {
    
    cout << endl;
    cout << c_name << endl;
    cout << c_gender << " " << c_race << " " << c_class << endl;
    for (int i = 0; i < STATS_COUNT; i++) {
        cout << STATS_NAMES[i] << ": " << c_stats[i] << endl;
    }
    
    
}
