#ifndef WORDCALCULATOR_H
#define	WORDCALCULATOR_H

#include <string>
#include <vector>
#include "WordInformation.h"
#include "WordsCollection.h"

class WordCalculator
{
    std::istream& input_stream_;
    const std::string separators_;
    WordsCollection words_;
    
    void addWordToWords(std::string& word);
public:
    WordCalculator(std::istream& input_stream, 
                   const std::string& separators);
    std::string getSeparators() const;
    void calculate();
    void output(std::ostream& output_stream) const;
};

#endif	/* WORDCALCULATOR_H */

