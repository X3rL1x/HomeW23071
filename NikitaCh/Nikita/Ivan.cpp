#include <iostream>
#include <string>
#include <sstream>

// ������� ��� ��������� ������ (���������� � ����������)
void generate_keys(int& e, int& d, int& n) {
    setlocale(LC_ALL, "RUS");
    int p = 61;  // ������� �����
    int q = 53;  // ������� �����
    n = p * q;   // ������
    int phi = (p - 1) * (q - 1); // ������� ������

    // ��������� e: �������� �����, ������� �������� � phi
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

    // ��������� d: ��������� ����� � e �� ������ phi
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
}

// ������� ����������
std::string encrypt(const std::string& message, int e, int n) {
    std::ostringstream encrypted;
    setlocale(LC_ALL, "RUS");

    for (char c : message) {
        long long enc = 1;
        for (int i = 0; i < e; i++) {
            enc = (enc * c) % n;
        }
        encrypted << enc << " ";  // ��������� ������������� ������ � ������ � ��������
    }

    return encrypted.str();  // ���������� ������
}

// ������� �����������
std::string decrypt(const std::string& encrypted, int d, int n) {
    setlocale(LC_ALL, "RUS");
    std::istringstream iss(encrypted);
    std::string decrypted;
    long long c;

    while (iss >> c) {  // ������ ������������� ����� �� ������
        long long dec = 1;
        for (int i = 0; i < d; i++) {
            dec = (dec * c) % n;
        }
        decrypted.push_back(static_cast<char>(dec));  // ����������� � ������ � ��������� � ������
    }

    return decrypted;  // ���������� �������������� ������
}