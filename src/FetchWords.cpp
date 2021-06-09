#include "FetchWords.h"

FetchWords::FetchWords()
{

}

std::string FetchWords::extractWords()
{
    randomWordsFile.open("resources/text/randomtext.txt");

    if (!randomWordsFile)
    {
        std::cout << "Error while opening file" << std::endl;
    }

    else if (randomWordsFile.is_open())
    {
        while (getline(randomWordsFile, word))
        {
            words.push_back(word);
        }

        temp = words[rand() % words.size()];

        return temp;
    }

    randomWordsFile.close();
}

