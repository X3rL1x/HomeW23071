#include <iostream>
#include <vector>
#include <string>

std::vector<long long> encrypt(const std::string& message, const std::string& key_word, int& n) {
    int p = 61;
    int q = 53;
    n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 0;
    for (char c : key_word) {
        e += c;
    }
    e = (e % (phi - 2)) + 2;

    std::vector<long long> encrypted;
    for (char c : message) {
        long long enc = 1;
        for (int i = 0; i < e; i++) {
            enc = (enc * c) % n;
        }
        encrypted.push_back(enc);
    }
    return encrypted;
}

std::string decrypt(const std::vector<long long>& encrypted, const std::string& key_word, int n) {
    int p = 61;
    int q = 53;
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

    std::string decrypted;
    for (long long c : encrypted) {
        long long dec = 1;
        for (int i = 0; i < d; i++) {
            dec = (dec * c) % n;
        }
        decrypted.push_back(static_cast<char>(dec));
    }
    return decrypted;
}