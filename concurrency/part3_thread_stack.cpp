/*

shared memory concurrency
each thread has it's own stack
reference to variable i on different stack

lifetime of i is reached early

while threads are executing they are seeing a momentary value of i
when the thread was constructed
this depends on the timing on the thread

typically referred to a race - accessing the same variable
 */

void theFun(int &i) // i is the shared variable here
{
    std::cout << "hi from " << i << std::endl;
}

void test(std::vector<std::thread> &workers)
{
    for (int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread(&thFun, std::ref(i)));
        // passed by reference
    }
}

int main()
{
    std::vector<std::thread> workers;
    test(workers);
    std::for_each(
        workers.begin(),
        workers.end(),
        [](std::thread &th) {
            th.join()
        });
    return 0;
}
