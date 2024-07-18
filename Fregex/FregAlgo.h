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
		void get_NFA_from_regex(std::string& regex, NFA& NFA);
	};
}

