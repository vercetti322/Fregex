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

	// return the character hash
	const std::unordered_map<char, uint8_t>& get_hash()
	{
		return hash;
	}

	// pack the key using input symbol and current state for transition map
	uint32_t pack_transition_key(uint8_t symbol, uint16_t state)
	{
		return (static_cast<uint32_t>(symbol) << 16) | state;
	}

	// unpack the transition map key to get input symbol & current state
	std::pair<uint8_t, uint16_t> unpack_transition_key(uint32_t key)
	{
		uint8_t symbol = static_cast<uint8_t>(key >> 16);
		uint16_t state = static_cast<uint16_t>(key & 0xFFFF);
		return {symbol, state};

	}


	void NFA::get_NFA_from_regex(std::string& regex)
	{

	}

	void DFA::get_DFA_from_regex(std::string& regex)
	{

	}

	bool DFA::string_acceptance(std::string& input)
	{
		
	}

}