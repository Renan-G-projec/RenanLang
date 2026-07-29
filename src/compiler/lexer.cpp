// Ad Maiorem Dei Gloriam!
#include "compiler/lexer.hpp"

bool Lexer::tokenize(const std::string& rawCode, lexer_output_t& tokenContainer) {
    std::stringstream codeStream{rawCode};
    std::string rawToken;
    
    scanCode(rawCode);
    evaluateCode(tokenContainer);
    return true;
}

#ifdef DEBUG

#endif