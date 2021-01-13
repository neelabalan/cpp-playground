#include <future>
#include <iostream>
#include <thread>

u_int32_t factorial( u_int32_t number ) {
    u_int32_t res = 1;
    for ( uint32_t i = number; i > 1; i-- ) {
        res *= i;
    }
    return res;
}

int main() {
    // below statement creates a new thread with std::async as launch policy
    // using std::deferred does not create a thread
    std::future<u_int32_t> val = std::async( 
        std::launch::async,
        factorial, 
        4 
    );
    auto result = val.get();
    return 0;
}