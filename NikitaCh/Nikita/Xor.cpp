#include <iostream>
#include <string>
#include <vector>
#include "HomeW23071.h"

std::string xor_encrypt(const std::string& key, const std::string& text) {
  std::string result = "";
  int key_len = key.length();
  for (size_t i = 0; i < text.length(); ++i) {
    result += (char)(text[i] ^ key[i % key_len]);
  }
  return result;
}

std::string xor_decrypt(const std::string& key, const std::string& encrypted_text) {
  return xor_encrypt(key, encrypted_text);
}
