#pragma once
/*
* Author: Jatin Jindal
* Github: vercetti322
*
* This class file contains all declarations of classes
* needed to store Regex, DFA & AST
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <fstream>
#include <memory>

namespace Fregex
{
	class DFA
	{
	private:
	public:
	};

	enum class NodeType
	{
		UnaryOperator, BinaryOperator, LeafSymbol
	};

	class AST
	{
	private:
		// UTF-8 symbol (operator or operand)
		char8_t node_idx;

		// first_pos set
		std::bitset<256> first_set;

		// last_pos set
		std::bitset<256> last_set;

		// follow_pos set
		std::bitset<128> follow_set;
		
		// create vector of unique_ptr refs (manage unary & binary operators)
		std::vector<std::unique_ptr<Fregex::AST>> child_refs;

		// ptr to parent (not unique to avoid circular dependency)
		AST* parent;

		// enum to hold kind of operator
		Fregex::NodeType node_type;

	public:
		// constructor to make AST node
		AST(const char8_t node_idx, const Fregex::NodeType operator_type);

		// print the node info
		void print_subtree(int level) const;

		// add a left child (Binary Operator)
		void add_left_child(std::unique_ptr<AST> left_child);

		// add a right child (Binary Operator)
		void add_right_child(std::unique_ptr<AST> right_child);

		// add a unary child (Unary Operator)
		void add_unary_child(std::unique_ptr<AST> unary_child);
	};

	class Regex
	{
	private:
		// non-augmented regex
		std::u8string regex;

		// augmented regex
		std::u8string augment_regex;
		
	public:
		// init the regex struct
		Regex(std::u8string& input);

		// augment the regex
		void augment();
		
		// getter for the private regex
		std::u8string get_regex();

		// getter for the private augmented regex
		std::u8string get_aug_regex();
	};
}
