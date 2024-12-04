#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;


template<typename Func, typename... Args>
auto measure_time(Func&& func, Args&&... args) {
    auto start = high_resolution_clock::now();
    auto result = func(forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return make_pair(result, duration);
}


int main() {
    string plaintext = "HELLO WORLD";
    string rsa_key = "dummy_key"; 
    string vigenere_key = "KEY";
    string playfair_key = "PLAYFAIR";

    string xor_key = "KEY";
    auto [xor_encrypted, xor_time] = measure_time(xor_encrypt, plaintext, xor_key);
    auto [xor_decrypted, xor_time_dec] = measure_time(xor_decrypt, xor_encrypted, xor_key);

    cout << "XOR Encryption: " << xor_encrypted << " (Time: " << xor_time << " µs)" << endl;
    cout << "XOR Decryption: " << xor_decrypted << " (Time: " << xor_time_dec << " µs)" << endl;

    return 0;
}