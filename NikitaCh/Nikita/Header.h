#pragma once
#ifndef ENCRYPTION_UTILS_H
#define ENCRYPTION_UTILS_H

#include <string>
#include <utility>
#include <chrono>
#include <vector>

using namespace std;

// Объявление функций шифрования и дешифрования
template<typename T> T Input(const int mode, const int mi, const int ma, const int foi);
vector<long long> encrypt(const string& message, const string& key_word, int& n);
string decrypt(const vector<long long>& encrypted, const string& key_word, int n);

// Другие объявления функций для шифрования (например, RSA, Виженера, Плейфейр)
// string rsa_encrypt(const string& plaintext, const string& rsa_key);
// string rsa_decrypt(const string& ciphertext, const string& rsa_key);
// string vigenere_encrypt(const string& plaintext, const string& key);
// string vigenere_decrypt(const string& ciphertext, const string& key);
// string playfair_encrypt(const string& plaintext, const string& key);
// string playfair_decrypt(const string& ciphertext, const string& key);

#endif // ENCRYPTION_UTILS_H