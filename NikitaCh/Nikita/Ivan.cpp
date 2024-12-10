#include <iostream>
#include <string>
#include <sstream>
#include "Header.h"

// Функция шифрования
std::string encrypt(const std::string& message, const std::string& key_word) {
    int p = 61; 
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 0;
    for (char c : key_word) {
        e += c; 
    }
    e = (e % (phi - 2)) + 2;

    std::ostringstream encrypted;
    for (char c : message) {
        long long enc = 1;
        for (int i = 0; i < e; i++) {
            enc = (enc * c) % n;
        }
        encrypted << enc << " "; 
    }

    return encrypted.str();
}

// Функция расшифровки
std::string decrypt(const std::string& encrypted, const std::string& key_word) {
    int p = 61;  
    int q = 53; 
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 0;
    for (char c : key_word) {
        e += c;  
    }
    e = (e % (phi - 2)) + 2; 

    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    std::istringstream iss(encrypted);
    std::string decrypted;
    long long c;

    while (iss >> c) {  
        long long dec = 1;
        for (int i = 0; i < d; i++) {
            dec = (dec * c) % n;
        }
        decrypted.push_back(static_cast<char>(dec));
    }

    return decrypted;  
}
