#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype>

using namespace std;

// Функция для создания матрицы 16x16
vector<vector<char>> prepareKey(const string& key) {
    setlocale(LC_ALL, "RUS");
    unordered_set<char> seen;
    string all_ascii = "";

    // Собираем все символы ASCII от 0 до 255
    for (int i = 0; i < 256; ++i) {
        all_ascii += static_cast<char>(i);
    }

    string combined = key;

    // Удаляем дублирующиеся символы из ключа
    for (char c : key) {
        seen.insert(c);
    }

    // Добавляем оставшиеся символы ASCII
    for (char c : all_ascii) {
        if (seen.find(c) == seen.end()) {
            combined += c;
            seen.insert(c);
        }
    }

    // Формируем матрицу 16x16
    vector<vector<char>> matrix(16, vector<char>(16));
    int idx = 0;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            matrix[i][j] = combined[idx++];
        }
    }

    return matrix;
}

// Функция шифрования
string encryptPlayfair(const string& text, const string& key) {
    setlocale(LC_ALL, "RUS");
    vector<vector<char>> matrix = prepareKey(key);
    string processedText = text;

    if (processedText.length() % 2 != 0) processedText += '\0';  // Добавляем нулевой символ, если длина нечетная

    string encryptedText = "";
    for (size_t i = 0; i < processedText.length(); i += 2) {
        char a = processedText[i];
        char b = processedText[i + 1];

        int row1, col1, row2, col2;
        for (int r = 0; r < 16; ++r) {
            for (int c = 0; c < 16; ++c) {
                if (matrix[r][c] == a) { row1 = r; col1 = c; }
                if (matrix[r][c] == b) { row2 = r; col2 = c; }
            }
        }

        if (row1 == row2) {
            encryptedText += matrix[row1][(col1 + 1) % 16];
            encryptedText += matrix[row2][(col2 + 1) % 16];
        }
        else if (col1 == col2) {
            encryptedText += matrix[(row1 + 1) % 16][col1];
            encryptedText += matrix[(row2 + 1) % 16][col2];
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
    setlocale(LC_ALL, "RUS");
    vector<vector<char>> matrix = prepareKey(key);
    string decryptedText = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        int row1, col1, row2, col2;
        for (int r = 0; r < 16; ++r) {
            for (int c = 0; c < 16; ++c) {
                if (matrix[r][c] == a) { row1 = r; col1 = c; }
                if (matrix[r][c] == b) { row2 = r; col2 = c; }
            }
        }

        if (row1 == row2) {
            decryptedText += matrix[row1][(col1 + 15) % 16];
            decryptedText += matrix[row2][(col2 + 15) % 16];
        }
        else if (col1 == col2) {
            decryptedText += matrix[(row1 + 15) % 16][col1];
            decryptedText += matrix[(row2 + 15) % 16][col2];
        }
        else {
            decryptedText += matrix[row1][col2];
            decryptedText += matrix[row2][col1];
        }
    }
    return decryptedText;
}