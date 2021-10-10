# Compile time string encryption
Compile time string encryption using C++20 consteval

Usage:<br>
`char* encrypted = ENCRYPT_STRING("This string is encrypted");`<br>
`wchar_t* encrypted_unicode = ENCRYPT_STRINGW(L"This unicode string is encrypted");`<br>

Disassembly of file with encrypted string:<br>
![Encryption demo](/images/string_encryption_demo_1.png)
![Encryption demo](/images/string_encryption_demo_2.png)
