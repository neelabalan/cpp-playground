#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main () {
	fs::path rootPath("/home/");
	for(auto &p : fs::directory_iterator("/home/user/")){
		std::cout<<p.path()<<"\n";
	}
}
