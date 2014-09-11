#include "WordInformation.h"

WordInformation::WordInformation(std::string word)
        :word_(word), amount_(0)
{}

std::string WordInformation::getWord() const
{
    return word_;
}

unsigned long WordInformation::getAmount() const
{
    return amount_;
}

void WordInformation::add()
{
    ++amount_;
}

bool WordInformation::operator<(const WordInformation& another_word) const
{
    if(getWord() < another_word.getWord())
    {
        return true;
    }
    return false;
}

bool WordInformation::operator==(const std::string& another_word) const
{
    if(getWord() == another_word)
    {
        return true;
    }
    return false;
}

