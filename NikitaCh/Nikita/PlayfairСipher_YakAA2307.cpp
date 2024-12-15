#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "HomeW23071.h"


using namespace std;

// Функция подготовки ключа
vector<vector<char>> prepareKey(const string& key) {
    string keyUpper = "";
    for (char c : key) {
        keyUpper += toupper(c);
    }

    string processedKey = "";
    for (char c : keyUpper) {
        if (isalpha(c) && c != 'J') {
            bool found = false;
            for (char k : processedKey) {
                if (toupper(k) == toupper(c)) {
                    found = true;
                    break;
                }
            }
            if (!found) processedKey += toupper(c);
        }
    }

    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ123456789";
    for (char c : alphabet) {
        bool found = false;
        for (char k : processedKey) {
            if (k == c) {
                found = true;
                break;
            }
        }
        if (!found) processedKey += c;
    }

    vector<vector<char>> matrix(5, vector<char>(5));
    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = processedKey[k++];
        }
    }
    return matrix;
}

// Функция шифрования
string encryptPlayfair(const string& text, const string& key) {
    vector<vector<char>> matrix = prepareKey(key);
    string processedText = "";
    for (char c : text) {
        if (isalpha(c)) processedText += toupper(c);
    }

    if (processedText.length() % 2 != 0) processedText += 'X';

    string encryptedText = "";
    for (size_t i = 0; i < processedText.length(); i += 2) {
        char a = processedText[i];
        char b = processedText[i + 1];

        int row1, col1, row2, col2;
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (matrix[r][c] == a) { row1 = r; col1 = c; }
                if (matrix[r][c] == b) { row2 = r; col2 = c; }
            }
        }

        if (row1 == row2) {
            encryptedText += matrix[row1][(col1 + 1) % 5];
            encryptedText += matrix[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2) {
            encryptedText += matrix[(row1 + 1) % 5][col1];
            encryptedText += matrix[(row2 + 1) % 5][col2];
        }
        else {
            encryptedText += matrix[row1][col2];
            encryptedText += matrix[row2][col1];
        }
    }
    return encryptedText;
}


// Функция дешифрования
string decryptPlayfair(const string& text, const string& key) {
    vector<vector<char>> matrix = prepareKey(key);
    string decryptedText = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (matrix[r][c] == a) { row1 = r; col1 = c; }
                if (matrix[r][c] == b) { row2 = r; col2 = c; }
            }
        }

        if (row1 == row2) {
            decryptedText += matrix[row1][(col1 + 4) % 5];
            decryptedText += matrix[row2][(col2 + 4) % 5];
        }
        else if (col1 == col2) {
            decryptedText += matrix[(row1 + 4) % 5][col1];
            decryptedText += matrix[(row2 + 4) % 5][col2];
        }
        else {
            decryptedText += matrix[row1][col2];
            decryptedText += matrix[row2][col1];
        }
    }
    return decryptedText;
}