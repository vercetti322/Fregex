/*
* Author: Jatin Jindal
* Github: vercetti322
* 
* The main entry point of the program where regex will be
* parsed against the tokens to get correct pairs.
*/

#include "FregAlgo.h"
#include "FregStructs.h"
#include <fstream>

// read from file and store regex pattern
static std::vector<std::string> read_regex_file(const std::string& filename)
{
    // defining the file for input
    std::ifstream file (filename, std::ios::in);

    // storing the regex
    std::vector<std::string> regex_list;
    if (file.is_open())
    {
        std::string regex;
        while (std::getline(file, regex))
            regex_list.push_back(regex);

        file.close();
    }

    else
    {
        std::cerr << "Error opening the file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    return regex_list;
}

// write to a file (vector of strings)
static void write_to_file(const std::string& filename, const std::vector<std::string>& output)
{
    // defining the output stream
    std::ofstream file(filename, std::ios::out);

    // openning the file and putting data
    if (file.is_open())
    {
        for (const auto& str : output)
        {
            file << str << '\n';
        }

        file.close();
        std::cout << "Data written to file successfully!" << std::endl;
    }

    else
    {
        std::cerr << "Error opening the file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    std::cout << "Init build successful!!" << std::endl << std::endl;
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";
    std::vector<std::string> regex_list = read_regex_file(input_file);
    std::vector<std::string> output_list;
    for (auto& regex : regex_list) 
    {
        Fregex::insert_explicit_concat(regex);
        std::string postfix = Fregex::infix_to_postfix(regex, Fregex::operand_set);
        output_list.push_back(postfix);
    }
    
    write_to_file(output_file, output_list);
    return 0;
}