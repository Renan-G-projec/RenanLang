// Ad Maiorem Dei Gloriam!
#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

enum Token {
    KEYWORD,
    LABEL,
    LITERAL,
    SEPARATOR
};

class Lexer {
public:
    void tokenize(const std::string& rawCode, std::vector<std::pair<Token, std::string>>& tokenContainer);
};

#endif