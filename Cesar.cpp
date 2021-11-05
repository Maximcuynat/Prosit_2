#include "Cesar.h"
#include <string>
#include <iostream>
using namespace std;
using namespace std::string_literals;
int key, num;
string Cesar_message;

string toBinary(int n){
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

string Cesar::Crypt_message(string message){
	cout << "Clef de cryptage : ";
	cin >> key;
	cout << "la clef : " << key << "\n";
	string MessageReturn;
	for (int i = 0; i < message.length(); i++) {
		if (toascii(static_cast<int>(message[i])) > 64 && toascii(static_cast<int>(message[i])) < 90) {
			cout << " -> MAJ\n";
		}
		else if (toascii(static_cast<int>(message[i])) > 96 && toascii(static_cast<int>(message[i])) < 123) {
			cout << " -> min\n";
		}
		else if (toascii(static_cast<int>(message[i])) == 95) {
			cout << " -> Espace \n";
			num = toascii(static_cast<int>(message[i])) + key;
		}
		cout << message[i] << " " << num << "\n";
		string tmp_string(1, char(num));
		MessageReturn.append(tmp_string);
	}

	return MessageReturn;
}
string Cesar::Decrypt_message(string message) {
	return message;
}
