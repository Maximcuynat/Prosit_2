#include "XOR.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
string enc, rt;
char ckey;

string XOR::EncryptageXor(string message){
	cout << " # Cle XOR : ";
	cin >> ckey;
	for (int i = 0; i < message.length(); i++) {
		enc += message[i] ^ (int(ckey) + 1) % 20;
	}
	rt = enc;
	enc = "";
	return rt;
}
