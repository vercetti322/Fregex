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
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <limits>

namespace Fregex
{
	// because 26 [a-z] + 26 [A-Z] + 10 [0-9] = 62 unique symbols
	constexpr uint8_t SYMBOL_COUNT = 62;

	// state encoding variables
	constexpr uint16_t MAX_STATE_COUNT = UINT16_MAX;

	// symbol => 1 byte int mapping
	extern std::unordered_map<char, uint8_t> hash;
	extern void init_symbol_hash(std::unordered_map<char, uint8_t>& hash);
	extern const std::unordered_map<char, uint8_t>& get_hash();


	class NFA
	{
	private:
		// set of states
		std::unordered_set<uint16_t> states;

		// status bitset (0 for non-accepting & 1 for accepting)

		// transition table (sparse vector)
	public:
		void get_NFA_from_regex(std::string& regex);
	};

	class DFA
	{
	private:
		// set of states
		std::unordered_set<uint16_t> states;

		// status bitset (0 for non-accepting & 1 for accepting)

		// transition table (sparse vector)
	public:
		void get_DFA_from_regex(std::string& regex);
	};
}
