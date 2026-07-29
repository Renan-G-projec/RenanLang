// Ad Maiorem Dei Gloriam!
#include "fileLoader.hpp"
#include <iostream>

void FileLoader::load(const std::string& filename, std::string& target) const {
    std::fstream fileStream(filename, std::ios::in);
    std::string buffer;

    while (std::getline(fileStream, buffer)) {
        target += buffer + '\n';
    }
}