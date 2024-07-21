/*
* Author: Jatin Jindal
* Github: vercetti322
*
* This class file contains all definitions of classes
* needed to store Regex, DFA & AST
*/

#include "FregStructs.h"

namespace Fregex
{
	Regex::Regex(std::u8string& input)
	{
		Regex::regex = input;
		Regex::augment_regex = u8"";
	}

	// augment the regex
	void Regex::augment()
	{
		for (size_t i = 0; i < Regex::regex.size() - 1; i++)
		{
			Regex::augment_regex += Regex::regex[i];
			if ((Regex::regex[i] == u8')' || Regex::regex[i] == u8'*' || Regex::regex[i] == u8'+' \
				|| isalnum(Regex::regex[i])) && (Regex::regex[i + 1] == u8'(' || Regex::regex[i + 1] == u8'#' || isalnum(Regex::regex[i + 1])))
			{
				Regex::augment_regex += u8'.';
			}
		}

		// augment the concat infused string
		Regex::augment_regex += u8'#';
	}

	// return non-augmented regex
	std::u8string Regex::get_regex()
	{
		return Regex::regex;
	}

	// return augmented regex
	std::u8string Regex::get_aug_regex()
	{
		return Regex::augment_regex;
	}

	// AST node construction operator
	AST::AST(const char8_t node_idx, const Fregex::NodeType node_type)
		: node_idx(node_idx), node_type(node_type), parent(nullptr)
	{
		// based on enum value define child references
		if (node_type == NodeType::BinaryOperator)
		{
			AST::child_refs.resize(2);
			AST::child_refs[0] = nullptr; // left child 
			AST::child_refs[1] = nullptr; // right child
		}

		else if (node_type == NodeType::UnaryOperator)
		{
			AST::child_refs.resize(1);
			AST::child_refs[0] = nullptr; // only child
		}

		else 
		{
			AST::child_refs.resize(0); // no children needed further
		}
	}

	// Print the node information for debugging
	void AST::print_subtree(int level = 0) const {
		// have to perform DFS to print info for each node
		std::string indent(level * 2, ' ');
		std::cout << indent << static_cast<char>(node_idx) << std::endl;
		std::cout << indent << "Node type: ";

		switch (node_type)
		{
			case Fregex::NodeType::UnaryOperator:
				std::cout << "UnaryOperator" << std::endl;
				break;
			case Fregex::NodeType::BinaryOperator:
				std::cout << "BinaryOperator" << std::endl;
				break;
			case Fregex::NodeType::LeafSymbol:
				std::cout << "LeafSymbol" << std::endl;
				break;
		}

		std::cout << indent << "Number of children: " << child_refs.size() << std::endl;

		// Print details of each child and recurse
		for (size_t i = 0; i < child_refs.size(); i++) {
			if (child_refs[i] != nullptr) {
				std::cout << indent << ((i == 0) ? "Left: " : "Right: ");
				std::cout << static_cast<char>(child_refs[i]->node_idx) << std::endl;
				// Recursively print the child node
				child_refs[i]->print_subtree(level + 1);
			}
			else {
				std::cout << indent << ((i == 0) ? "Left: " : "Right: ") << "None" << std::endl;
			}
		}
	}

	// add the left child node to parent node (if its left child is null and its
	// node_type is not leaf (does not include unary left child))
	void AST::add_left_child(std::unique_ptr<AST> left_child)
	{
		if (AST::node_type == Fregex::NodeType::BinaryOperator \
			&& AST::child_refs[0] == nullptr)
		{
			AST::child_refs[0] = std::move(left_child);
			if (AST::child_refs[0] != nullptr)
			{
				AST::child_refs[0]->parent = this;
			}
		} 

		else
		{
			std::cerr << "Error: attempted to set left child on non-binary/ leaf parent or to a non-null left child";
		}
	}

	// add the right child node to parent node (if its right child is null and its
	// node_type is not leaf)
	void AST::add_right_child(std::unique_ptr<AST> right_child)
	{
		if (AST::node_type == Fregex::NodeType::BinaryOperator \
			&& AST::child_refs[1] == nullptr)
		{
			AST::child_refs[1] = std::move(right_child);
			if (AST::child_refs[1] != nullptr)
			{
				AST::child_refs[1]->parent = this;
			}
		}

		else
		{
			std::cerr << "Error: attempted to set left child on non-binary/leaf parent or to a non-null right child";
		}
	}

	// add the unary child node to parent node (if its only child is null and its
	// node_type is not leaf)
	void AST::add_unary_child(std::unique_ptr<AST> unary_child)
	{
		if (AST::node_type == Fregex::NodeType::UnaryOperator \
			&& AST::child_refs[0] == nullptr)
		{
			AST::child_refs[0] = std::move(unary_child);
			if (AST::child_refs[0] != nullptr)
			{
				AST::child_refs[0]->parent = this;
			}
		}

		else
		{
			std::cerr << "Error: attempted to set the child on binary/leaf parent or to a non-null unary child";
		}
	}
}