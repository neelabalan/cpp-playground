#include <iostream>
#include <ostream>
#include <array>

using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::array;
using std::size_t;

template <typename T, size_t N>
inline ostream & operator << (ostream &out, array<T, N> content) 
{
    for(auto i : content)
    {
        out<<i<<endl;
    }
    return out;
}
int main()
{
    array<int, 5> marks = {10, 10, 30, 40, 40};
    cout<<marks;
}

