#pragma once
/*
* Author: Jatin Jindal
* Github: vercetti322
* 
* This header files contains all specifications of structures
* needed to store Automate (NFA & DFA)
*/

// include directives
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>

namespace Fregex
{
	struct DFA
	{
	private:
	public:
	};

	struct Regex
	{
	private:
		// regex
		std::string regex;
		
	public:
		// init the regex struct
		Regex(std::string& input);

		// augment the regex
		void augment();
		
		// getter for the private regex
		std::string get_regex();
	};
}
