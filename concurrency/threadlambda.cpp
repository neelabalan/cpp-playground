#include <iostream>
#include <thread>

int main()
{
	std::thread t([]() -> void { std::cout << "hello from thread ";});
	t.join();
}