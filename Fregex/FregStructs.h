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
	extern std::unordered_map<char, uint8_t> symbol_hash;

	// list of operands with priorites=> |, *, +, ?, .
	extern std::unordered_map<char, uint8_t> operand_set;

	extern void init_symbol_hash(std::unordered_map<char, uint8_t>& hash);
	
	extern const std::unordered_map<char, uint8_t>& get_hash();

	extern uint32_t pack_transition_key(uint8_t symbol, uint16_t state);

	extern std::pair<uint8_t, uint16_t> unpack_transition_key(uint32_t key);

	class NFA
	{
	private:
		// set of states
		std::unordered_set<uint16_t> states;

		// status bitset (0 for non-accepting & 1 for accepting)
		std::unordered_set<bool> status; // true for accepting, false for not accepting

		// start state
		uint8_t start;

		// transition table (sparse vector)
		// uint32_t can be unpacked to get uint8_t & uint16_t
		std::unordered_map<uint32_t, std::unordered_set<uint16_t>> transitions;
	};

	class DFA
	{
	private:
		// set of states
		std::unordered_set<uint16_t> states;

		// status bitset (0 for non-accepting & 1 for accepting)
		std::unordered_set<bool> status; // true for accepting, false for not accepting

		// start state
		uint8_t start;

		// transition table (sparse vector)
		// uint32_t can be unpacked to get uint8_t & uint16_t
		std::unordered_map<uint32_t, uint16_t> transitions;
	};
}
