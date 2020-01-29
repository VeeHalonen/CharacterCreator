

#ifndef CHARSHEET_H
#define CHARSHEET_H
#include <string>
#include <vector>

class CharSheet 
{
    
private:
        std::string c_name;
        std::string c_race;
        std::string c_class;
        std::string c_gender;
        static const int MAX_STAT_POINTS = 20;
        static const int STATS_COUNT = 4;  // How many different stats there are
        int c_stats[STATS_COUNT];
        
public:
    
    // Constructors
    CharSheet();
    CharSheet(std::string, std::string, std::string, int, int[CharSheet::STATS_COUNT]);
    CharSheet(bool);
    CharSheet(bool, bool, bool, bool, bool);
    
    // Copy constructor
    CharSheet (const CharSheet &);
    
    // Functions for generating class variables - can be called without an object
    static std::string generateName(bool);
    static std::string generateRandomName();
    static std::string generateRace(bool);
    static std::string generateGender(bool);
    static std::string generateClass(bool);
    
    // Getters
    std::string getName();
    std::string getRace();
    std::string getGender();
    std::string getClass();
    std::vector<int> getStats();
    
    // Setters
    void setName(std::string);
    void setRace(std::string);
    void setGender(std::string);
    void setClass(std::string);
    void setStats(bool);
    
    void printCharacter();
};

#endif /* CHARSHEET_H */

