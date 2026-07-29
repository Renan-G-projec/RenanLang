// Ad Maiorem Dei Gloriam!
#ifndef RENANLANG_HPP
#define RENANLANG_HPP

#include "fileLoader.hpp"
#include "compiler/compiler.hpp"
#include "virtualMachine.hpp"

class RenanLang {
public:
    RenanLang() = default;
    RenanLang(const RenanLang& other) = delete;

    void loadFile(const char* fileName);
    void init();

private:
    VirtualMachine mVM;
    FileLoader mFileloader;
    Compiler mCompiler;
    
    std::string mLoadedCode;
    std::int8_t mCompiledCode[100];
};

#endif