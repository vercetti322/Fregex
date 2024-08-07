﻿/*
* Author: Jatin Jindal
* Github: vercetti322
* 
* The main entry point of the program where regex will be
* parsed against the tokens to get correct pairs.
*/

#include "FregStructs.h"

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
    // make an AST node with 2 children;
    auto root = std::make_unique<Fregex::AST>(u8'.', Fregex::NodeType::BinaryOperator);

    auto left = std::make_unique<Fregex::AST>(u8'*', Fregex::NodeType::UnaryOperator);

    auto leaf = std::make_unique<Fregex::AST>(u8'a', Fregex::NodeType::LeafSymbol);

    auto right = std::make_unique<Fregex::AST>(u8'b', Fregex::NodeType::LeafSymbol);

    left->add_unary_child(std::move(leaf));

    root->add_left_child(std::move(left));

    root->add_right_child(std::move(right));
    
    root->print_subtree(0);

    return 0;
}