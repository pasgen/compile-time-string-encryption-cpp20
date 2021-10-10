#include <iostream>

#include "string_encryption.h"

int main() {
    std::cout << ENCRYPT_STRING("Test test test") << std::endl;
    std::wcout << ENCRYPT_STRINGW(L"Unicode test unicode test unicode test") << std::endl;
    return 0;
}