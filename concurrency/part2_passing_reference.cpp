#include <thread>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

// writing to the stack at the same time
void thFun( int &i ) {
    std::cout << "Hi from worker " << i << "\n";
}

int main() 
{
    std::vector< std::thread > workers;
    for( int i = 0; i < 8; i++ ){
        auto th = std::thread( &thFun, std::ref( i ));
        workers.push_back( std::move( th ));
        assert( !th.joinable() );
    }

    std::cout << "hi from main!";

    std::for_each( 
        workers.begin(), 
        workers.end(), 
        []( std::thread &th ) {
            assert( th.joinable() );
            th.join();
        }
    );

    return 0;
}

/* 
 * output
 
>> ./a.out
Hi from worker Hi from worker 22
Hi from worker 4

Hi from worker 5
Hi from worker 6
Hi from worker 7
hi from main!Hi from worker 8
Hi from worker 8

*/
