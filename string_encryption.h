#pragma once

#define COMPILE_TIME_RANDOM ((__COUNTER__ + 1) * ((__TIME__[0] - '0') * 100000 + (__TIME__[1] - '0') * 10000 + \
                                              (__TIME__[3] - '0') * 1000 + (__TIME__[4] - '0') * 100 +      \
                                              (__TIME__[6] - '0') * 10 + __TIME__[7] - '0'))

template <int Length, char Key>
struct EncryptedString {
    char string[Length];

    consteval void EncryptString(const char* str) {
        for (int i = 0; i < Length; i++) {
            string[i] = str[i];
            string[i] ^= Key;
        }
    }
    char* DecryptString() {
        for (int i = 0; i < Length; i++) {
            string[i] ^= Key;
        }
        return string;
    }

};

template <int Length, char Key>
consteval EncryptedString<Length, Key> EncryptStringImpl(const char* str) {
    auto res = EncryptedString<Length, Key>();
    res.EncryptString(str);
    return res;
}

#define ENCRYPT_STRING(str) EncryptStringImpl<sizeof(str), (COMPILE_TIME_RANDOM % 256)>(str).DecryptString()

template <int Length, wchar_t Key>
struct EncryptedStringW {
    wchar_t string[Length];

    consteval void EncryptString(const wchar_t* str) {
        for (int i = 0; i < Length; i++) {
            string[i] = str[i];
            string[i] ^= Key;
        }
    }
    wchar_t* DecryptString() {
        for (int i = 0; i < Length; i++) {
            string[i] ^= Key;
        }
        return string;
    }

};

template <int Length, wchar_t Key>
consteval EncryptedStringW<Length, Key> EncryptStringWImpl(const wchar_t* str) {
    auto res = EncryptedStringW<Length, Key>();
    res.EncryptString(str);
    return res;
}

#define ENCRYPT_STRINGW(str) EncryptStringWImpl<sizeof(str) / 2, (COMPILE_TIME_RANDOM % 65535)>(str).DecryptString()