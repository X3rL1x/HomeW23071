#pragma once
#ifndef ENCRYPTION_UTILS_H
#define ENCRYPTION_UTILS_H

#include <string>
#include <utility>
#include <chrono>
#include <vector>

using namespace std;

// Объявление функций шифрования и дешифрования
string encrypt(const std::string& message, const std::string& key_word);
string decrypt(const std::string& encrypted, const std::string& key_word);

// Другие объявления функций для шифрования (например, RSA, Виженера, Плейфейр)
// string rsa_encrypt(const string& plaintext, const string& rsa_key);
// string rsa_decrypt(const string& ciphertext, const string& rsa_key);
// string vigenere_encrypt(const string& plaintext, const string& key);
// string vigenere_decrypt(const string& ciphertext, const string& key);
// string playfair_encrypt(const string& plaintext, const string& key);
// string playfair_decrypt(const string& ciphertext, const string& key);

#endif // ENCRYPTION_UTILS_H