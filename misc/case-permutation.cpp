#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>

std::vector<std::string> casePermutation(std::string str)
{
	std::vector<std::string> permutations;
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	unsigned int max = 1 << str.length(); // total number of permutations 2^n

	// Using all subsequences and permuting them
	for (int i = 0; i < max; i++)
	{
		// If j-th bit is set, we convert it to upper case
		std::string combination = str;
		for (int j = 0; j < str.length(); j++)
		{
			if (((i >> j) & 1) == 1)
			{
				combination[j] = toupper(str.at(j));
			}
		}
		permutations.push_back(combination); // push back current combination
	}
	return permutations;
}
int main()
{

	auto perm = casePermutation("abc");
	for (auto p : perm)
	{
		std::cout << p << "\n";
	}

	return 0;
}
