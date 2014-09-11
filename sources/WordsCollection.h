#ifndef WORDSCOLLECTION_H
#define	WORDSCOLLECTION_H

#include <vector>
#include "WordInformation.h"
#include <iostream>

class WordsCollection
{
    std::vector<WordInformation> words_;
    std::string toLowerCase(const std::string& word);
public:
    WordsCollection();
    void addWord(const std::string& word);
    void sort();
    void output(std::ostream& output_stream) const;
};

#endif	/* WORDSCOLLECTION_H */

