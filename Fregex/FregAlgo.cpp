#include "FregAlgo.h"

namespace Fregex
{
    // to check if a character is an operator
    bool is_operator(char c)
    {
        return (c == '+' || c == '*' || c == '|' || c == '?' || c == '.');
    }

    void insert_explicit_concat(std::string& regex)
    {
        for (size_t i = 0; i < regex.size() - 1; ++i)
        {
            if ((isalnum(regex[i]) || regex[i] == ')' || regex[i] == '*') && (isalnum(regex[i + 1]) || regex[i + 1] == '('))
            {
                regex.insert(i + 1, ".");
                i++;
            }
        }
    }

    // e.g. => convert (ab) --> ab.
    std::string infix_to_postfix(const std::string& regex, const std::unordered_map<char, uint8_t>& operand_set)
    {
        // init the stack
        std::stack<char> operators;
        
        // init the postfix string
        std::string postfix = "";

        // going thru our input
        for (size_t i = 0; i < regex.size(); i++)
        {
            char c = regex[i];
            if (isalnum(c))
            {
                postfix += c;
            }

            else if (c == '(')
            {
                // just push it (in hopes of ')' occurence later)
                operators.push(c);
            }

            else if (c == ')')
            {
                // remove everything between '(' & ')' from stack
                while (!operators.empty() && operators.top() != '(')
                {
                    postfix += operators.top();
                    operators.pop();
                }

                operators.pop(); // to pop the corresponding '('
            }

            else if (is_operator(c))
            {
                // according to operator preference, pop stuff out and push the incoming operator
                while (!operators.empty() && Fregex::operand_set[c] <= Fregex::operand_set[operators.top()])
                {
                    postfix += operators.top();
                    operators.pop();

                }

                operators.push(c);
            }   
        }

        while (!operators.empty())
        {
            postfix += operators.top();
            operators.pop();
        }

        return postfix;
    }

    void get_NFA_from_regex(std::string& regex, NFA& NFA)
    {

    }

    void get_DFA_from_NFA(NFA& NFA, DFA& DFA)
    {

    }

    bool string_acceptance(std::string& input, DFA& DFA)
    {
        return false;
    }
}