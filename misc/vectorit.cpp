#include <iostream>
#include <iterator>
#include <vector>
 
int main() 
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 ,9 };
    int j = 4;
    auto vi = v.begin();
    std::advance(vi, j);
 
    std::cout << *vi << '\n';
}