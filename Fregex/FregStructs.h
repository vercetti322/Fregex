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
	
	struct NFA
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

	struct DFA
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
