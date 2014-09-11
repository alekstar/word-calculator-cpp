#include <string>

#ifndef WORDINFORMATION_H
#define	WORDINFORMATION_H

class WordInformation
{
    std::string word_;
    unsigned long amount_;
public:
    WordInformation(std::string word);
    std::string getWord() const;
    unsigned long getAmount() const;
    void add();
    bool operator<(const WordInformation& another_word) const;
    bool operator==(const std::string& another_word) const;
};

#endif	/* WORDINFORMATION_H */

