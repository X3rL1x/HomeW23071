#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include "Header.h"

using namespace std;
using namespace std::chrono;

int main() {
	setlocale(LC_ALL, "Russian");
	string text = "ILOVEGUBKINUNIVERSITY";
	string code;
	string key = "123";
	cout << "Output XOR code" << endl;
	code = encryptMessage(key, text);
	cout << code << endl;
	cout << "Output XOR decrypt" << endl;
	code = decryptMessage(key, code);
	cout << code << endl;
	return 0;
}