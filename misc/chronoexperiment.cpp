
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer
{
	private:
		std::chrono::time_point< std::chrono::system_clock > startingTime;
		std::chrono::time_point< std::chrono::system_clock > endingTime;
		bool isRunning = false;

	public:
		void start()
		{
			startingTime = std::chrono::system_clock::now();
			isRunning = true;
		}

		void stop()
		{
			endingTime = std::chrono::system_clock::now();
			isRunning = false;
		}

		double elapsedMilliseconds()
		{
			std::chrono::time_point<std::chrono::system_clock> endTime;

			if (isRunning)
			{
				endTime = std::chrono::system_clock::now();
			}
			else
			{
				endTime = endingTime;
			}

			return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startingTime).count();
		}

		double elapsedSeconds()
		{
			return elapsedMilliseconds() / 1000.0;
		}


};

long fibonacci(unsigned n)
{
	if (n < 2)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

	Timer timer;
	timer.start();

	std::cout<<"fibo : "<<fibonacci(42);
	timer.stop();
	std::cout<<"elapsed time";
	std::cout<<timer.elapsedMilliseconds();
}