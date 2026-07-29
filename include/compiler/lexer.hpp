// Ad Maiorem Dei Gloriam!
#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <optional>

enum Token {
    KEYWORD,
    LABEL,
    LITERAL,
    SEPARATOR
};

enum EvaluateToken {

};

typedef std::vector<std::pair<EvaluateToken, std::optional<std::string>>> lexer_output_t;

class Lexer {
public:
    bool tokenize(const std::string& rawCode, lexer_output_t& tokenContainer);
    std::string getError();

private:
    typedef std::vector<std::pair<Token, std::string>> scanned_code_t;
    scanned_code_t mScannedCode;

    bool mRunning = true;
    std::string errorMessage = "";

    Token getToken(const std::string& token);

    void scanCode(const std::string& code);
    void evaluateCode(lexer_output_t& output);

    bool isComment(const std::string& token);
    bool isKeyword(const std::string& token);
    bool isLabel(const std::string& token);
    bool isLiteral(const std::string& token);
    bool isSeparator(const std::string& token);
};

#endif