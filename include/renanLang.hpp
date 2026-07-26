// Ad Maiorem Dei Gloriam!
#ifndef RENANLANG_HPP
#define RENANLANG_HPP

#include "fileLoader.hpp"
#include "compiler.hpp"

class RenanLang {
public:
    RenanLang() = default;
    RenanLang(const RenanLang& other) = delete;

    void loadFile(const char* fileName);
    void init();

private:
    // VirtualMachine mVM;
    FileLoader mFileloader;
    Compiler mCompiler;
    
    std::stringstream mLoadedCode;
    bytecode_t mCompiledCode[2];
};

#endif