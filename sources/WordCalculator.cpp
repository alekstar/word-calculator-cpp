#include "WordCalculator.h"
#include <string>
#include <algorithm>
#include <iostream>

WordCalculator::WordCalculator(std::istream& input_stream, 
                               const std::string& separators)
    :input_stream_(input_stream), separators_(separators + '\377')
{
}

std::string WordCalculator::getSeparators() const
{
    return separators_;
}

void WordCalculator::addWordToWords(std::string& word)
{
    if(!word.empty())
    {
        words_.addWord(word);
        word.clear();
    }   
}

void WordCalculator::calculate()
{
    std::string word;
    while(!input_stream_.eof())
    {
        char symbol;
        symbol = input_stream_.get();
        
        if(std::find(separators_.begin(), separators_.end(), symbol) == 
            separators_.end())
        {
            word.push_back(symbol);
        }
        else
        {
            addWordToWords(word);
        }
    };
    addWordToWords(word);
    
    words_.sort();
}

void WordCalculator::output(std::ostream& output_stream) const
{
    words_.output(output_stream);
}

