#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>


int main() {
    std::cout << "Program counts the frequency of words in the text\n"
                 "\tfrom file entered by user\n\n";
    std::cout << "Enter full name of the file: ";
    std::string filename;
    std::cin >> filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ifstream file;
    file.open(filename);
    if (!file.good()) {
        std::cout << "File not found!\n";
        return 0;
    }

    std::map<std::string, int, std::less<std::string>> wordFrequency;
    std::cout << "Container max size: " << wordFrequency.max_size() << " records\n";
    while (!file.eof()) {
        char symbol = file.get();
        bool conditionLower = symbol >= 'a' && symbol <= 'z';
        bool conditionUpper = symbol >= 'A' && symbol <= 'Z';
        if (conditionLower || conditionUpper) {
            std::string word;
            bool conditionDash = false;
            bool conditionDigit = false;
            do {
                word.push_back(tolower(symbol));
                symbol = file.get();
                conditionLower = symbol >= 'a' && symbol <= 'z';
                conditionUpper = symbol >= 'A' && symbol <= 'Z';
                conditionDigit = symbol >= '0' && symbol <= '9';
                conditionDash = symbol == '-' || symbol == '\'';
            } while (!file.eof() && (conditionLower || conditionUpper
                                     || conditionDigit || conditionDash));

            std::map<std::string, int, std::less<std::string>>::iterator wordFreqIter;
            wordFreqIter = wordFrequency.find(word);
            if (wordFreqIter != wordFrequency.end())
                wordFreqIter->second++;
            else
                wordFrequency[word] = 1;
        }
    }
    file.close();

    std::cout << "\nThe word count is complete, so here is the overall table:\n";
    std::cout << std::setfill('-') << std::setw(69) << '-' << std::setfill(' ') << std::endl;

    std::map<std::string, int, std::less<std::string>>::iterator wordIter;
    wordIter = wordFrequency.begin();
    int totalWords = 0;
    bool newString = false;
    while (wordIter != wordFrequency.end()) {
        std::cout << std::setw(20) << wordIter->first << std::setiosflags(std::ios::left)
                  << "  =  " << std::setw(5) << wordIter->second
                  << std::resetiosflags(std::ios::left);
        if (newString) {
            std::cout << std::endl;
            newString = false;       
        }
        else {
            std::cout << " |  ";
            newString = true;
        }
        totalWords += wordIter->second;
        wordIter++;
    }
    if (newString)
        std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(69) << '-' << std::setfill(' ') << std::endl;
    std::cout << "Unique words:  " << wordFrequency.size() << std::endl;
    std::cout << std::setfill('-') << std::setw(31) << '-' << std::setfill(' ') << std::endl;   
    std::cout << "Total count of word:  " << totalWords << std::endl;
    std::cout << std::setfill('-') << std::setw(69) << '-' << std::setfill(' ') << std::endl;


    return 0;
}