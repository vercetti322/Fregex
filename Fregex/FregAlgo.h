#pragma once
/*
* Author: Jatin Jindal
* Github: vercetti322
*
* This header files contains all specifications of alogrithms
* pertaining to string postfix, NFA to DFA conversion, DFA acceptance & Regex to NFA parsing.
*/

// include directives
#include <iostream>
#include <emmintrin.h> // for SSE2 vectorization
#include "FregStructs.h"

namespace Fregex 
{
	class Algo
	{
	public:
		void infix_to_postfix(std::string& regex);

		void get_NFA_from_regex(std::string& regex, NFA& NFA);

		void get_DFA_from_NFA(NFA& NFA, DFA& DFA);

		bool string_acceptance(std::string& input, DFA& DFA);
	};
}

