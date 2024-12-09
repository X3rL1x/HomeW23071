#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>
#include "Header.h"

using namespace std;
using namespace std::chrono;

int main() {
	setlocale(LC_ALL, "Russian");
	string text = "ILOVEGUBKINUNIVERSITY";
	string code;
	string key = "ABCFIJSIJUHWHC";
	cout << "Output XOR code" << endl;
	code = encryptPlayfair(text, key);
	cout << code << endl;
	cout << "Output XOR decrypt" << endl;
	code = decryptPlayfair(text, key);
	cout << code << endl;
	return 0;
}
