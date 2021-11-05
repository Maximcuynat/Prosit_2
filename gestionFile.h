#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class gestionFile{
private:
	string message;
public:
	void openFileAndSave(string);
	string ReadFile();
};

