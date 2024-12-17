#include <iostream>
#include <string>
#include <sstream>

// Функция для генерации ключей (публичного и приватного)
void generate_keys(int& e, int& d, int& n) {
    setlocale(LC_ALL, "RUS");
    int p = 61;  // Простое число
    int q = 53;  // Простое число
    n = p * q;   // Модуль
    int phi = (p - 1) * (q - 1); // Функция Эйлера

    // Генерация e: простого числа, взаимно простого с phi
    e = 2;
    while (e < phi) {
        int gcd = phi;
        int temp_e = e;
        while (temp_e != 0) {
            int temp = gcd % temp_e;
            gcd = temp_e;
            temp_e = temp;
        }
        if (gcd == 1) break;
        e++;
    }

    // Генерация d: обратного числа к e по модулю phi
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
}

// Функция шифрования
std::string encrypt(const std::string& message, int e, int n) {
    std::ostringstream encrypted;
    setlocale(LC_ALL, "RUS");

    for (char c : message) {
        long long enc = 1;
        for (int i = 0; i < e; i++) {
            enc = (enc * c) % n;
        }
        encrypted << enc << " ";  // Добавляем зашифрованный символ в строку с пробелом
    }

    return encrypted.str();  // Возвращаем строку
}

// Функция расшифровки
std::string decrypt(const std::string& encrypted, int d, int n) {
    setlocale(LC_ALL, "RUS");
    std::istringstream iss(encrypted);
    std::string decrypted;
    long long c;

    while (iss >> c) {  // Читаем зашифрованные числа из строки
        long long dec = 1;
        for (int i = 0; i < d; i++) {
            dec = (dec * c) % n;
        }
        decrypted.push_back(static_cast<char>(dec));  // Преобразуем в символ и добавляем к строке
    }

    return decrypted;  // Возвращаем расшифрованную строку
}