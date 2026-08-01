// Ad Maiorem Dei Gloriam!
#include "fileLoader.hpp"
#include <iostream>

void FileLoader::load(const std::string& filename, std::string& target) const {
    std::fstream fileStream(filename, std::ios::in);
    std::string buffer;

    if (!fileStream.is_open()) {
        std::cout << "Fatal error: " << filename << " not found.\n";
        std::cout << "Exiting the program.\n";
        exit(0);
    }

    while (std::getline(fileStream, buffer)) {
        target += buffer + '\n';
    }
}