#include <iostream>
#include <iterator>
#include <algorithm>
#include <ostream>

class fibit
{
    size_t i {0};
    size_t a {0};
    size_t b {1};

public:
    constexpr fibit() = default;

    constexpr fibit(size_t b_, size_t a_, size_t i_)
        : i{i_}, a{a_}, b{b_}
    {}

    size_t operator*() const { return b; }

    constexpr fibit& operator++() {
        const size_t old_b {b};
        b += a;
        a  = old_b;
        ++i;
        return *this;
    }

    bool operator!=(const fibit &o) const { return i != o.i; }
};

int main() {
    fibit it;
    const fibit end {0, 0, 20};

    while (it != end) {
        std::cout << *it << '\n';
        ++it;
    }

    std::copy(it, end, std::ostream_iterator<size_t>{std::cout,"\n"});
}
