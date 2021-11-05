#pragma once
#include <string>
using namespace std;

class Cesar{
private:
	string message;
public:
	string Crypt_message(string);
	string Decrypt_message(string);
};

