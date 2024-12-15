    #include <iostream>
    #include <string>
    #include <algorithm>
    #include "HomeW23071.h"

    using namespace std;

    // Функция для шифрования сообщения
    string encryptMessage(const string& key, const string& message) {
        string encryptedMessage;
        int keyLength = key.length();

        for (size_t i = 0; i < message.length(); ++i) {
            char c = message[i];
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = key[i % keyLength] - '0';
                encryptedMessage += (c - base + shift) % 26 + base;
            } else {
                encryptedMessage += c; 
            }
        }

        return encryptedMessage;
    }

    // Функция для дешифрования сообщения
    string decryptMessage(const string& key, const string& encryptedMessage) {
        string decryptedMessage;
        int keyLength = key.length();

        for (size_t i = 0; i < encryptedMessage.length(); ++i) {
            char c = encryptedMessage[i];
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = key[i % keyLength] - '0';
                decryptedMessage += (c - base - shift + 26) % 26 + base;
            } else {
                decryptedMessage += c; 
            }
        }

        return decryptedMessage;
    }