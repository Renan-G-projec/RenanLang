// Ad Maiorem Dei Gloriam!
#include "compiler/lexer.hpp"

bool Lexer::tokenize(const std::string& rawCode, scanned_code_t& tokenContainer) {
    std::string rawToken;
    
    scanCode(rawCode);
    if (mRunning) {
        tokenContainer = mScannedCode;
        return true;
    } else {
        std::cout << "ERROR: During lexical analisys: " << getError() << '\n';
        return false;
    }
}

void Lexer::scanCode(const std::string& rawCode) {
    mCurrentPos = 0;

    enum State {
        NONE,
        COMMENT,
        STRING_LITERAL,
        CHAR_LITERAL
    };

    State currentState = NONE;
    while (mCurrentPos < rawCode.length() && mRunning) {
        const char currentChar = rawCode[mCurrentPos];

        switch (currentState) {
            case State::NONE: {
                // Skiping blank characters
                if (isWhitespace(currentChar)) break;
                if (isAlpha(currentChar)) {
                    std::string alphanumericContent{currentChar};
                    while (isAlphanumeric(rawCode[++mCurrentPos])) alphanumericContent += rawCode[mCurrentPos];
                    if (isKeyword(alphanumericContent)) {
                        mScannedCode.push_back({Token::KEYWORD, alphanumericContent});
                        break;
                    } else {
                        mScannedCode.push_back({rawCode[++mCurrentPos] == ':' ? Token::LABEL : Token::LABEL_IDENTIFIER, alphanumericContent});
                    }

                    if (!isWhitespace(rawCode[mCurrentPos])) {
                        mRunning = false;
                        errorMessage = alphanumericContent + " is not a valid label name.";
                    }
                } else if (isDigit(currentChar)) {
                    std::string numberLiteralContent{currentChar};
                    while (!isWhitespace(rawCode[++mCurrentPos])) {
                        if (!isDigit(rawCode[mCurrentPos])) {
                            mRunning = false;
                        }
                        numberLiteralContent += rawCode[mCurrentPos];
                    }
                    if (!mRunning) errorMessage = numberLiteralContent + " is not a recognized number literal.";
                    mScannedCode.push_back({Token::NUM_LITERAL, numberLiteralContent});
                } else if (currentChar == '\'') {
                    currentState = CHAR_LITERAL;
                } else if (currentChar == '"') {
                    currentState = STRING_LITERAL;
                    mCurrentPos--;
                } else if (currentChar == ';') {
                    mScannedCode.push_back({Token::SEPARATOR, ";"});
                }
                break;
            }
            case State::COMMENT: {
                while (!isNewline(rawCode[++mCurrentPos]));
                currentState = NONE;
                break; 
            }
            case State::STRING_LITERAL: {
                std::string strLiteral;
                while (rawCode[++mCurrentPos] != '"') strLiteral += rawCode[mCurrentPos];
                mScannedCode.push_back({Token::STRING_LITERAL, strLiteral});
                currentState = NONE;

                break;
            }
            case State::CHAR_LITERAL: {
                char ch = rawCode[mCurrentPos++];
                mScannedCode.push_back({Token::CHAR_LITERAL, std::string{ch}});
                currentState = NONE;

                break;
            }
        }
        mCurrentPos++; // Scapes trailing character such as \n ' and "
    }
}

bool Lexer::isWhitespace(char ch) {
    return ch == '\n' || ch == ' ' || ch == '\r' || ch == '\0' || ch == '\t';
}

bool Lexer::isNewline(char ch) {
    return ch == '\n';
}

bool Lexer::isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool Lexer::isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool Lexer::isAlphanumeric(char ch) {
    return isDigit(ch) || isAlpha(ch);
}

bool Lexer::isKeyword(const std::string& token) {
    return
        token == "PUSH"                 || token == "PRINT"       || token == "PRINT_ASCII" ||
        token == "JMP"                  || token == "JMP_IF_ZERO" || token == "JMP_LABEL"   ||
        token == "JMP_IF_ZERO_LABEL"    || token == "HALT";
}

const std::string& Lexer::getError() { 
    return errorMessage;
}

#ifdef DEBUG

std::string getTokenTypeName(Token token) {
    switch (token) {
        case Token::KEYWORD: 
            return "KEYWORD";
        case Token::LABEL:
            return "LABEL";
        case Token::LABEL_IDENTIFIER:
            return "LABEL_IDENTIFIER";
        case Token::CHAR_LITERAL:
            return "CHAR_LITERAL";
        case Token::NUM_LITERAL:
            return "NUM_LITERAL";
        case Token::STRING_LITERAL:
            return "STRING_LITERAL";
        case Token::SEPARATOR:
            return "SEPARATOR";
    }
}

void Lexer::printLexerOutput(scanned_code_t scannedCode) {
    for (auto token : scannedCode) std::cout << "Type: " << getTokenTypeName(token.first) << " Value:" << token.second << '\n';
}

#endif