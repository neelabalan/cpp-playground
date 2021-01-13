
#include <iostream>
bool isAlternating(int n)
{
    // auto lastdigit = n%10;
    // if( (lastdigit != 5) || (lastdigit != 1) || (lastdigit != 0) || (lastdigit != 2)){
    //     return false;
    // }
    int temp = (n & 1);
    n >>= 1;
    while (n)
    {
        if (temp == (n & 1))
        {
            return true;
        }
        temp = !temp;
        n >>= 1;
    }
    return false;
}
int main()
{

    int n = 7;
    std::cout<<isAlternating(5);
    return 0;
}
