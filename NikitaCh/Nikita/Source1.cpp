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
	string key = "ABCFSDCSVWG";
	cout << "Output Playfair code" << endl;
	code = encryptPlayfair(text, key);
	cout << code << endl;
	cout << "Output Playfair decrypt" << endl;
	code = decryptPlayfair(code, key);
	cout << code << endl;
	return 0;
}
