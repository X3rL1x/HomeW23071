#pragma once
#ifndef ENCRYPTION_UTILS_H
#define ENCRYPTION_UTILS_H

#include <string>
#include <utility>
#include <chrono>

using namespace std;
template<typename Func, typename... Args>
auto measure_time(Func&& func, Args&&... args);
template<typename T> T Input(const int mode, const int mi, const int ma, const int foi);
void XOR(string text, string key);
void Playfair(string text, string key);
void RSA(string text);
void Vijener(string text, string key);
void start();
void InText(string& intext);
void InKey(string& inkey);
void test(string& intext, string& inkey);
void appendCharacters(string& str, char character, size_t count);
void insertAlternatingChars(string& original, char char1, char char2, int count);
string xor_encrypt(const string& plaintext, const string& key);
string xor_decrypt(const string& ciphertext, const string& key);
string encryptPlayfair(const string& text, const string& key);
string decryptPlayfair(const string& text, const string& key);
void generate_keys(int& e, int& d, int& n);
string encrypt(const std::string& message, int e, int n);
string decrypt(const std::string& encrypted, int d, int n);
string encryptMessage(const string& key, const string& message);
string decryptMessage(const string& key, const string& encryptedMessage);
string xor_encrypt(const string& plaintext, const string& key);
string xor_decrypt(const string& ciphertext, const string& key);

#endif // ENCRYPTION_UTILS_H