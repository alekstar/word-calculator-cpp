#include "WordsCollection.h"
#include <algorithm>
#include <locale>

WordsCollection::WordsCollection()
{}

void WordsCollection::addWord(const std::string& word)
{
    std::string lower_case_word = toLowerCase(word);
    std::vector<WordInformation>::iterator found_word = 
        std::find(words_.begin(), words_.end(), lower_case_word);
    if(found_word != words_.end())
    {
        found_word->add();
    }
    else
    {
        WordInformation word_information(lower_case_word);
        word_information.add();
        words_.push_back(word_information);
    }
}

void WordsCollection::output(std::ostream& output_stream) const
{
    for(std::vector<WordInformation>::const_iterator words_iterator = 
            words_.begin();
        words_iterator != words_.end();
        ++words_iterator)
    {
        output_stream << "word: ";
        output_stream.width(25);
        output_stream.setf(std::ios::left);
        output_stream << words_iterator->getWord() << 
                         " amount:" << words_iterator->getAmount() << 
                         std::endl;
    }
}

void WordsCollection::sort()
{
    std::sort(words_.begin(), words_.end());
}

std::string WordsCollection::toLowerCase(const std::string& word)
{
    std::locale locale;
    std::string lower_case_string;
    for(std::size_t word_index = 0; word_index < word.length(); ++word_index)
    {
        lower_case_string.push_back(std::tolower(word[word_index], locale));
    }
    return lower_case_string;
}
