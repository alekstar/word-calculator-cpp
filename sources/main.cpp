#include <string>
#include <iostream>
#include "WordCalculator.h"
#include "WordsCollection.h"
#include <fstream>

int main(int argc, char** argv)
{   
    const std::string DEFAULT_WORD_SEPARATORS("=+-*/~`<>|\\() _,.:;!?\n\"'-");
    const std::size_t OUTPUT_FILE_ARGUMENT_INDEX = 2;
    const std::size_t SEPARATORS_ARGUMENT_INDEX = 3;
    
    std::ifstream input_file_stream(argv[1]);
    std::string separators(DEFAULT_WORD_SEPARATORS);
    if(argc < 2)
    {
        return 0;
    }
    if(argc > 3)
    {
        separators = std::string(argv[SEPARATORS_ARGUMENT_INDEX]);
    }
    if (!input_file_stream.fail())
    {
        WordCalculator word_calculator(input_file_stream,
                                       separators);
        word_calculator.calculate();
        if(argc > 2)
        {
            std::ofstream output_file_stream(
                argv[OUTPUT_FILE_ARGUMENT_INDEX]);
            word_calculator.output(output_file_stream);
        }
        else
        {
            word_calculator.output(std::cout);
        }
    }
    return 0;
}
