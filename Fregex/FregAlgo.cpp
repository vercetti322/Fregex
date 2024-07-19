#include "FregAlgo.h"

namespace Fregex
{
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