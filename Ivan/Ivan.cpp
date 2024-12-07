#include <iostream>
#include <vector>
#include <cmath>
#include <string>

std::string RSA_encrypt_decrypt(const std::string& input) {
    int p = 61;
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 3;
    while (e < phi) {
        int a = e, b = phi, gcd = 0;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        gcd = a;
        if (gcd == 1) break;
        e += 2;
    }

    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    std::cout << "Открытый ключ (e, n): (" << e << ", " << n << ")\n";
    std::cout << "Закрытый ключ (d, n): (" << d << ", " << n << ")\n";

    std::vector<long long> encrypted;
    for (char c : input) {
        long long enc = 1;
        for (int i = 0; i < e; i++) {
            enc = (enc * c) % n;
        }
        encrypted.push_back(enc);
    }

    std::cout << "Зашифрованное сообщение: ";
    for (long long c : encrypted) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    std::string decrypted;
    for (long long c : encrypted) {
        long long dec = 1;
        for (int i = 0; i < d; i++) {
            dec = (dec * c) % n;
        }
        decrypted.push_back(static_cast<char>(dec));
    }

    std::cout << "Расшифрованное сообщение: " << decrypted << "\n";

    return decrypted;
}