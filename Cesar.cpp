#include "Cesar.h"
#include <string>
#include <iostream>
using namespace std;
using namespace std::string_literals;
int key, num;
string MessageReturn;

// ---------------------------------------------------------------------------------------------------- Private

void Cesar::adtolist(int size, int Code, string MessageReturn){
	string tmp_string(size, char(Code));
	MessageReturn.append(tmp_string);
}

int Cesar::KeyCode(){int key;cout << " # Cle Cesar : ";cin >> key;return key;}

// ---------------------------------------------------------------------------------------------------- Public

string Cesar::Crypt_message(string message){
	MessageReturn = "";
	key = KeyCode();
	for (int i = 0; i < message.length(); i++) {
		num = toascii(static_cast<int>(message[i]));
		if      (num > 64 && num < 91 ) { num = num + key; while (num > 91 ) { num = num - 26; } }
		else if (num > 96 && num < 123) { num = num + key; while (num > 122) { num = num - 26; } }
		string tmp_string(1, char(num));
		MessageReturn.append(tmp_string);
	}return MessageReturn;
}

string Cesar::Decrypt_message(string message) {
	MessageReturn = "";
	key = KeyCode();
	for (int i = 0; i < message.length(); i++) {
		num = static_cast<int>(message[i]);
		if      (num > 64 && num < 91 ) {num = num - key; while (num < 64) {num = num + 26; } }
		else if (num > 96 && num < 123) {num = num - key; while (num < 96) {num = num + 26; } }
		string tmp_string(1, char(num));
		MessageReturn.append(tmp_string);
	}return MessageReturn;
}