#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int SIZE = 5;

// Функция для создания квадрата Полибия
string createPlayfairMatrix(const string& key) {
    string matrix;
    unordered_set<char> usedChars;
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Игнорируем 'J'
    string fullKey = key + alphabet;

    for (char c : fullKey) {
        c = toupper(c);
        if (c == 'J') c = 'I'; // Заменяем 'J' на 'I'
        if (usedChars.find(c) == usedChars.end()) {
            matrix += c;
            usedChars.insert(c);
        }
    }

    return matrix;
}

// Функция для поиска позиции символа в матрице
pair<int, int> findPosition(const string& matrix, char c) {
    size_t pos = matrix.find(c);
    return {pos / SIZE, pos % SIZE};
}

// Функция для шифрования пары символов
string encryptPair(const string& matrix, char a, char b) {
    auto posA = findPosition(matrix, a);
    auto posB = findPosition(matrix, b);

    if (posA.first == posB.first) { // Одинаковые строки
        return {matrix[posA.first * SIZE + (posA.second + 1) % SIZE], matrix[posB.first * SIZE + (posB.second + 1) % SIZE]};
    } else if (posA.second == posB.second) { // Одинаковые столбцы
        return {matrix[((posA.first + 1) % SIZE) * SIZE + posA.second], matrix[((posB.first + 1) % SIZE) * SIZE + posB.second]};
    } else { // Разные строки и столбцы
        return {matrix[posA.first * SIZE + posB.second], matrix[posB.first * SIZE + posA.second]};
    }
}

// Функция для дешифрования пары символов
string decryptPair(const string& matrix, char a, char b) {
    auto posA = findPosition(matrix, a);
    auto posB = findPosition(matrix, b);

    if (posA.first == posB.first) { // Одинаковые строки
        return {matrix[posA.first * SIZE + (posA.second - 1 + SIZE) % SIZE], matrix[posB.first * SIZE + (posB.second - 1 + SIZE) % SIZE]};
    } else if (posA.second == posB.second) { // Одинаковые столбцы
        return {matrix[((posA.first - 1 + SIZE) % SIZE) * SIZE + posA.second], matrix[((posB.first - 1 + SIZE) % SIZE) * SIZE + posB.second]};
    } else { // Разные строки и столбцы
        return {matrix[posA.first * SIZE + posB.second], matrix[posB.first * SIZE + posA.second]};
    }
}

// Функция для шифрования сообщения
string encryptMessage(const string& key, const string& message) {
    string matrix = createPlayfairMatrix(key);
    string encryptedMessage;
    string processedMessage = message;
    processedMessage.erase(remove(processedMessage.begin(), processedMessage.end(), ' '), processedMessage.end()); // Удаляем пробелы
    for (char& c : processedMessage) {
        c = toupper(c);
        if (c == 'J') c = 'I'; // Заменяем 'J' на 'I'
    }

    for (size_t i = 0; i < processedMessage.size(); i += 2) {
        if (i + 1 < processedMessage.size() && processedMessage[i] == processedMessage[i + 1]) {
            processedMessage.insert(i + 1, "X"); // Вставляем 'X' между одинаковыми символами
        }
    }

    if (processedMessage.size() % 2 != 0) {
        processedMessage += 'X'; // Добавляем 'X' в конец, если длина нечетная
    }

    for (size_t i = 0; i < processedMessage.size(); i += 2) {
        encryptedMessage += encryptPair(matrix, processedMessage[i], processedMessage[i + 1]);
    }

    return encryptedMessage;
}

// Функция для дешифрования сообщения
string decryptMessage(const string& key, const string& encryptedMessage) {
    string matrix = createPlayfairMatrix(key);
    string decryptedMessage;

    for (size_t i = 0; i < encryptedMessage.size(); i += 2) {
        decryptedMessage += decryptPair(matrix, encryptedMessage[i], encryptedMessage[i + 1]);
    }

    return decryptedMessage;
}