// Ad Maiorem Dei Gloriam!
#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

enum Token {
    KEYWORD,
    LABEL,
    LITERAL
};

class Lexer {
public:
    void tokenize(const std::string& rawCode, std::vector<std::pair<Token, std::string>>& tokenContainer);
};

#endif