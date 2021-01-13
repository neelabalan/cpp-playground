// Generate All Subsets of an Array
// [1 2 3] -> [] [1] [2] [3] [1 2] [2 3] [1 3] [1 2 3]
// Using Bitmasking

#include<iostream>
#include<vector>
auto generateSubsets(std::vector<unsigned long> vec)
{
	int range = 1 << vec.size();
	std::vector<std::vector<unsigned long>> set;
	std::vector<unsigned long> subset;

	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (i & (1 << j))
			{
				subset.push_back(vec[j]);
			}
		}
		set.push_back(subset);
		subset.clear();
	}

	return set;
}

int main()
{
	auto subsets = generateSubsets(std::vector<unsigned long>{1,2,3,4,5,6,7,8,9});
	for (auto vec : subsets){
		for( auto elements : vec){

			std::cout<<elements<<" ";
		}
		std::cout<<"\n";
	}
	
	return 0;
}
