#include <filesystem>
#include <iostream>

using namespace std::filesystem;
using std::endl;

int main() {
	path pathToDisplay("/home/user/");
	for (path::iterator itr = pathToDisplay.begin(); itr != pathToDisplay.end(); itr++){
		std::cout<<"path ->"<<*itr;
	}
    std::cout << L"root_name() = " << pathToDisplay.root_name() << endl
        << L"root_path() = " << pathToDisplay.root_path() << endl
        << L"relative_path() = " << pathToDisplay.relative_path() << endl
        << L"parent_path() = " << pathToDisplay.parent_path() << endl
        << L"filename() = " << pathToDisplay.filename() << endl
        << L"stem() = " << pathToDisplay.stem() << endl
        << L"extension() = " << pathToDisplay.extension() << endl;
}
