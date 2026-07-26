// Ad Maiorem Dei Gloriam!
#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <string>
#include <sstream>
#include <fstream>

class FileLoader {
public:
    void load(const std::string& filename, std::stringstream& target) const;
};

#endif