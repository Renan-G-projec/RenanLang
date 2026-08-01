// Ad Maiorem Dei Gloriam!
#include "renanLang.hpp"

void RenanLang::loadFile(const char *fileName) {
    mFileloader.load(fileName, mLoadedCode);
    mCompiler.compile(mLoadedCode, mCompiledCode);
    return;
}

void RenanLang::init() {
    mVM.loadBytecode(mCompiledCode);
    mCompiledCode.clear();
    mVM.init();
    return;
}