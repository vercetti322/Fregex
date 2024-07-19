#include "FregStructs.h"

namespace Fregex
{
	Regex::Regex(std::string& input)
	{
		Regex::regex = input;
	}

	// augment the regex
	void Regex::augment()
	{
		for (size_t i = 0; i < Regex::regex.size() - 1; i++)
		{
			if ((Regex::regex[i] == ')' || Regex::regex[i] == '*' || Regex::regex[i] == '+' \
				|| isalnum(Regex::regex[i])) && (Regex::regex[i + 1] == '(' || isalnum(Regex::regex[i + 1])))
			{
				Regex::regex.insert(i + 1, "."); i++;
				std::cout << Regex::regex << std::endl;
			}
		}

		// augment the concat infused string
		Regex::regex += '#';
	}

	std::string Regex::get_regex()
	{
		return Regex::regex;
	}
}