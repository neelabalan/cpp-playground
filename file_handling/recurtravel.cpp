#include <iostream>
#include <filesystem>

int main(){
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    for (const auto& dirEntry : recursive_directory_iterator("/home/user/")){
        if(std::filesystem::is_regular_file(dirEntry)){
            std::cout << dirEntry << std::endl;
        }
    }
}
