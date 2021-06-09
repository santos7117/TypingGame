#ifndef FETCHWORDS_H
#define FETCHWORDS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>




class FetchWords
{
    public:
        FetchWords();

        // Functions

        std::string extractWords(void);


        // Variables

        std::string word, temp;
        std::ifstream randomWordsFile;
        std::vector <std::string> words;

};

#endif // FETCHWORDS_H

