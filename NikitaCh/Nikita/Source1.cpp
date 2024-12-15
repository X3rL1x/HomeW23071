#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include "HomeW23071.h"

using namespace std;
using namespace std::chrono;

template<typename Func, typename... Args>
auto measure_time(Func&& func, Args&&... args) {
	auto start = high_resolution_clock::now();
	auto result = std::forward<Func>(func)(std::forward<Args>(args)...);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Время выполнения - " << duration.count() << " микросекунд" << endl;
	return result;
}
template<typename T> T Input(int mode, int mi, int ma, int foi) {
	string str;
	T r;
	if (mode == 1) {
		if (foi == 1) {
			while (true) {
				getline(cin, str);
				bool onlyDigits = true;
				for (char c : str) {
					if (!isdigit(c) and c != '.') {
						onlyDigits = false;
						break;
					}
				}
				if (!onlyDigits) {
					cout << "Ошибка ввода!" << endl;
				}
				else {
					stringstream ss(str);
					if (!(ss >> r) || r < mi || r > ma) {
						cout << "Ошибка ввожа!" << endl;
					}
					else {
						return r;
						break;
					}
				}
			}
		}
		else {
			while (true) {
				getline(cin, str);
				bool onlyDigits = true;
				for (char c : str) {
					if (!isdigit(c)) {
						onlyDigits = false;
						break;
					}
				}
				if (!onlyDigits) {
					cout << "Ошибка ввода!" << endl;
				}
				else {
					stringstream ss(str);
					if (!(ss >> r) || r < mi || r > ma) {
						cout << "Ошибка ввода!" << endl;
					}
					else {
						return r;
						break;
					}
				}
			}
		}
	}
	if (mode == 2) {
		if (foi == 1) {
			while (true) {
				getline(cin, str);
				bool onlyDigits = true;
				for (char c : str) {
					if (!isdigit(c) and c != '.') {
						onlyDigits = false;
						break;
					}
				}
				if (!onlyDigits) {
					cout << "Ошибка ввода!" << endl;
				}
				else {
					stringstream ss(str);
					if (!(ss >> r) || r < 0) {
						cout << "Ошибка ввода!" << endl;
					}
					else {
						return r;
						break;
					}
				}
			}
		}
		else {
			while (true) {
				getline(cin, str);
				bool onlyDigits = true;
				for (char c : str) {
					if (!isdigit(c)) {
						onlyDigits = false;
						break;
					}
				}
				if (!onlyDigits) {
					cout << "Ошибка ввода!" << endl;
				}
				else {
					stringstream ss(str);
					if (!(ss >> r) || r < 0) {
						cout << "Ошибка ввода!" << endl;
					}
					else {
						return r;
						break;
					}
				}
			}
		}
	}
}
void start()
{
	string intext = "A";
	string inkey = "A";
	do
	{
		int c = 1;
		cout << "Выберите пункт" << endl
			<< "1. Ввести текст для шифрования" << endl
			<< "2. Ввести ключ для шифрования" << endl
			<< "3. Протестировать XOR" << endl
			<< "4. Протестирровать Playfair (шифрует только латиницу)" << endl
			<< "5. Протестировать RSA (работает только с ключом на латинице)" << endl
			<< "6. Протестировать Vijener" << endl
			<< "7. Выбрать тестовые входные данные (текст и ключ)" << endl
			<< "0. Выход" << endl;

		c = Input<int>(1, 0, 7, 0);

		switch (c)
		{
		case 1:
			cin.clear();
			InText(intext);
			break;
		case 2:
			cin.clear();
			InKey(inkey);
			break;
		case 3:
			cin.clear();
			XOR(intext,inkey);
			break;
		case 4:
			cin.clear();
			Playfair(intext,inkey);
			break;
		case 5:
			cin.clear();
			RSA(intext);
			break;
		case 6:
			cin.clear();
			Vijener(intext,inkey);
			break;
		case 7:
			cin.clear();
			test(intext, inkey);
			break;
		case 0:
			cin.clear();
			exit(0);
		default:
			cin.clear();
			cout << "Ошибка ввода!" << endl;
		}
	} while (true);
}
void InText(string &intext) {
	cout << "Введите текст для шифрования:" << endl;
	getline(cin, intext);
}
void InKey(string &inkey) {
	cout << "Введите ключ для шифрования:" << endl;
	getline(cin, inkey);
}
void XOR(string text, string key) {
	string code;
	cout << "Вывод кода и времени:" << endl;
	code = measure_time(xor_encrypt, key, text);
	cout << code << endl << endl;
	cout << "Вывод дешифрованного текста и времени:" << endl;
	code = measure_time(xor_decrypt, key, code);
	cout << code << endl << endl;
}
void Playfair(string text, string key) {
	string code;
	cout << "Вывод кода и времени:" << endl;
	code = measure_time(encryptPlayfair, text, key);
	cout << code << endl << endl;
	cout << "Вывод дешифрованного текста и времени:" << endl;
	code = measure_time(decryptPlayfair, code, key);
	cout << code << endl << endl;
}
void RSA(string text){
	int n = 0, e = 0, d = 0;
	string code;
	generate_keys(e,d,n);
	cout << "Вывод кода и времени:" << endl;
	code = measure_time(encrypt,text, e, n);
	cout << code << endl << endl;
	cout << "Вывод дешифрованного текста и времени:" << endl;
	code = measure_time(decrypt, code, d, n);
	cout << code << endl << endl;
}
void Vijener(string text, string key) {
	string code;
	cout << "Вывод кода и времени:" << endl;
	code = measure_time(encryptMessage, key, text);
	cout << code << endl << endl;
	cout << "Вывод дешифрованного текста и времени:" << endl;
	code = measure_time(decryptMessage, key, code);
	cout << code << endl << endl;
}

void test(string &intext, string &inkey) {
	setlocale(LC_ALL, "Russian");
	int l = 1;
	cout << "Выберите пункт" << endl
		<< "1. 1000 символов А с ключом X" << endl
		<< "2. 2000 символов АB с ключом X" << endl
		<< "3. 10000 символов АB с ключом X" << endl
		<< "4. 10000 символов A с ключом X" << endl
		<< "5. 1000 символов 12 с ключом X" << endl
		<< "6. 1000 пробелов с ключом пробел" << endl
		<< "0. Выход" << endl;

	l = Input<int>(1, 0, 7, 0);
	switch (l)
	{
	case 1:
		cin.clear();
		appendCharacters(intext, 'A', 1000);
		appendCharacters(inkey, 'X', 1);
		break;
	case 2:
		cin.clear();
		insertAlternatingChars(intext, 'A', 'B', 1000);
		appendCharacters(inkey, 'X', 1);
		break;
	case 3:
		cin.clear();
		insertAlternatingChars(intext, 'A', 'B', 10000);
		appendCharacters(inkey, 'X', 1);
		break;
	case 4:
		cin.clear();
		appendCharacters(intext, 'A', 10000);
		appendCharacters(inkey, 'X', 1);
		break;
	case 5:
		cin.clear();
		insertAlternatingChars(intext, '1', '2', 1000);
		appendCharacters(inkey, 'X', 10);
		break;
	case 6:
		cin.clear();
		appendCharacters(intext, ' ', 1000);
		appendCharacters(inkey, ' ', 10);
		break;
	default:
		cin.clear();
		cout << "Ошибка ввода!" << endl;
	}
}
void appendCharacters(string& str, char character, size_t count) {
	str = "";
	str.append(count, character);
}
void insertAlternatingChars(string& original, char char1, char char2, int count) {
	original = "";
	for (int i = 0; i < count; ++i) {
		original += (i % 2 == 0) ? char1 : char2;
	} 
}
int main() 
{
	setlocale(LC_ALL, "Russian");
	start();
	return 0;
}

