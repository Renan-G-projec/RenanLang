// Ad Maiorem Dei Gloriam!
#include "main.hpp"

inline void print_usage() {
    std::cout << "Usage: RenanLang <bytecode-file>\n";
    return;
}

int main(int argc, const char** argv) {
    if (argc < 2) print_usage();
    RenanLang renanLang;

    renanLang.loadFile(argv[1]);
}