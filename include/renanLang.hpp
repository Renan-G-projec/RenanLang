// Ad Maiorem Dei Gloriam!
#ifndef RENANLANG_HPP
#define RENANLANG_HPP

class RenanLang {
public:
    RenanLang() = default;
    RenanLang(const RenanLang& other) = delete;

    void loadFile(const char* fileName);
    void init();

private:
    // VirtualMachine mVM;
    // FileLoader mFileloader;
    // Compiler mCompiler
    
    // std::stringstream mLoadedCode;
    // uint8_buffer mCompiledCode
};

#endif