#pragma once
#ifndef ENCRYPTION_UTILS_H
#define ENCRYPTION_UTILS_H

#include <string>
#include <utility>
#include <chrono>

using namespace std;

// Объявление функций шифрования и дешифрования
template<typename T> T Input(const int mode, const int mi, const int ma, const int foi);
string encryptMessage(const string& key, const string& message);
string decryptMessage(const string& key, const string& encryptedMessage);

// Другие объявления функций для шифрования (например, RSA, Виженера, Плейфейр)
// string rsa_encrypt(const string& plaintext, const string& rsa_key);
// string rsa_decrypt(const string& ciphertext, const string& rsa_key);
// string vigenere_encrypt(const string& plaintext, const string& key);
// string vigenere_decrypt(const string& ciphertext, const string& key);
// string playfair_encrypt(const string& plaintext, const string& key);
// string playfair_decrypt(const string& ciphertext, const string& key);

#endif // ENCRYPTION_UTILS_H