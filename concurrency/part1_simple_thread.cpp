#include <iostream>
#include <thread>
#include <algorithm>

int main() {
    std::vector< std::thread > workers;
    for ( int i = 0; i < 10; i++ )
    {
        workers.push(
            std::thread(
                []() {
                    std::cout << "Hi from thread" << std::endl;
                }
            )
        );
    }
    std::cout << "Hi from main";
    std::for_each( 
        workers.begin(), 
        workers.end(), 
        []( std::thread &th ) {
            th.join();
        }
    );
    th.join();
    return 0;
}
