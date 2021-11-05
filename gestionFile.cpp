#include "gestionFile.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void gestionFile::openFileAndSave(string message){
	string const flux("C:/Users/maxcu/Documents/000000 CESI/A2/2 Conception et programmation objet (partie 1)/Prosit 2 Fini les spaghettis !/Message.txt");
	ofstream monFlux(flux.c_str());
	monFlux << message;
}

string gestionFile::ReadFile(){
	return string();
}
