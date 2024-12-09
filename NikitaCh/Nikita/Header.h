#pragma once
#ifndef ENCRYPTION_UTILS_H
#define ENCRYPTION_UTILS_H

#include <string>
#include <utility>
#include <chrono>

using namespace std;

// ���������� ������� ���������� � ������������
string encryptPlayfair(const string& text, const string& key);
string decryptPlayfair(const string& text, const string& key);

// ������ ���������� ������� ��� ���������� (��������, RSA, ��������, ��������)
// string rsa_encrypt(const string& plaintext, const string& rsa_key);
// string rsa_decrypt(const string& ciphertext, const string& rsa_key);
// string vigenere_encrypt(const string& plaintext, const string& key);
// string vigenere_decrypt(const string& ciphertext, const string& key);
// string playfair_encrypt(const string& plaintext, const string& key);
// string playfair_decrypt(const string& ciphertext, const string& key);

#endif // ENCRYPTION_UTILS_H