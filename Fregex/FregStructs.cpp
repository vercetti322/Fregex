#include "FregStructs.h"

namespace Fregex
{
	// hash to be init
	std::unordered_map<char, uint8_t> Fregex::hash;

	// init the hash
	void Fregex::init_symbol_hash(std::unordered_map<char, uint8_t>& hash)
	{
		std::cout << "initialising the hash..." << std::endl;
		for (uint8_t i = 0; i < SYMBOL_COUNT; ++i)
		{
			// [a-z] --> (0, 1, ..., 25)
			if (i >= 0 && i < 26)
				hash['a' + i] = i;
			// [A-Z] --> (26, 27, ..., 51)
			else if (i >= 26 && i < 52)
				hash['A' + (i - 26)] = i;
			// [0-9] --> (52, 53, ..., 61)
			else
				hash['0' + (i - 52)] = i;
		}
	}

	const std::unordered_map<char, uint8_t>& get_hash()
	{
		return hash;
	}


	void NFA::get_NFA_from_regex(std::string& regex)
	{

	}

	void DFA::get_DFA_from_regex(std::string& regex)
	{

	}
}