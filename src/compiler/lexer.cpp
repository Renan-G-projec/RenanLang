// Ad Maiorem Dei Gloriam!
#include "compiler/lexer.hpp"

void Lexer::tokenize(const std::string& rawCode, std::vector<std::pair<Token, std::string>>& tokenContainer) {
    std::stringstream codeStream{rawCode};
    std::string rawToken;
    while (codeStream >> rawToken) {
        std::cout << rawToken << ' ';
    }
}

#ifdef DEBUG

#endif