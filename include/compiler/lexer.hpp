// Ad Maiorem Dei Gloriam!
#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <optional>

enum Token {
    KEYWORD,
    LABEL,
    LABEL_IDENTIFIER,
    STRING_LITERAL,
    CHAR_LITERAL,
    NUM_LITERAL,
    SEPARATOR
};

typedef std::vector<std::pair<Token, std::string>> scanned_code_t;

class Lexer {
public:
    bool tokenize(const std::string& rawCode, scanned_code_t& tokenContainer);
    const std::string& getError();

    void printLexerOutput(scanned_code_t& scannedCode);

private:
    scanned_code_t mScannedCode;

    bool mRunning = true;
    std::string errorMessage = "";

    unsigned int mCurrentPos = 0;

    Token getToken(const std::string& token);

    void scanCode(const std::string& code);

    // Helper functions
    bool isWhitespace(char);
    bool isNewline(char);
    bool isAlpha(char);
    bool isDigit(char);
    bool isAlphanumeric(char);
    bool isKeyword(const std::string&);
};

#endif