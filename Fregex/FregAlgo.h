#pragma once
/*
* Author: Jatin Jindal
* Github: vercetti322
*
* This header files contains all specifications of alogrithms
* pertaining to string postfix, NFA to DFA conversion, DFA acceptance & Regex to NFA parsing.
*/

// include directives
#include "FregStructs.h"
#include <set>
#include <stack>

namespace Fregex 
{
		extern void get_NFA_from_regex(std::string& regex, NFA& NFA);

		extern void get_DFA_from_NFA(NFA& NFA, DFA& DFA);

		extern bool string_acceptance(std::string& input, DFA& DFA);

		extern bool is_operator(char c);

		extern void insert_explicit_concat(std::string& regex);
}

