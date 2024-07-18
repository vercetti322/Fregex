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

        // get the size of postfix
        uint16_t postfix_size = 0;
        for (const auto& ch : regex)
            if (isalnum(ch) || Fregex::operand_set.find(ch) != Fregex::operand_set.end())
            {
                postfix_size++;
            }
        
        // init the postfix string
        std::string postfix(postfix_size, '_');

        // going thru our input
        int iter = 0; // for output
        for (size_t i = 0; i < regex.size(); i++)
        {
            char c = regex[i];
            if (isalnum(c))
            {
                postfix[iter] = c; 
                iter++;
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
                    postfix[iter] = operators.top();
                    iter++;
                    operators.pop();
                }

                operators.pop(); // to pop the corresponding '('
            }

            else if (is_operator(c))
            {
                // according to operator preference, pop stuff out and push the incoming operator
                while (!operators.empty() && Fregex::operand_set[c] <= Fregex::operand_set[operators.top()])
                {
                    postfix[iter] = operators.top();
                    iter++;
                    operators.pop();

                }

                operators.push(c);
            }   
        }

        while (!operators.empty())
        {
            postfix[iter] = operators.top();
            iter++;
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