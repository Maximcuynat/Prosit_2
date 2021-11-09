#pragma once
#include <string>
using namespace std;

class Cesar{
private:
	void adtolist(int, int, string);
	int  KeyCode();
public:
	string Crypt_message(string);
	string Decrypt_message(string);
};

