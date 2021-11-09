#include "gestionFile.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string path, nameFile;
bool placement;

void gestionFile::openFileAndSave(string message){
	system("cls");
	
	cout << "Indiquer l'emplacement de destination du fichier ou 0 pour le fichier de destination par defaut.\n**> ";
	cin >> path;
	if (path == "0"){
		path = "C:/Users/maxcu/Documents";
	}
	cout << "Indiquer le nom du ficher\n**> ";
	cin >> nameFile;
	path = path + "/" + nameFile + ".txt";
	string const flux(path);
	ofstream monFlux(flux.c_str());
	monFlux << message;
}

string gestionFile::ReadFile(){
	string DataReturn;
	cout << "Indiquer l'emplacement de destination du fichier\n**> ";
	cin >> path;
	cout << "Indiquer le nom du ficher\n**> ";
	cin >> nameFile;
	path = path + "/" + nameFile + ".txt";
	ifstream Flux(path);
	if (Flux) {
		string letter;
		while (Flux >> letter) {
			for (int i = 0; i < letter.length(); i++) {
				string tmp_string(1, char(letter[i]));
				DataReturn.append(tmp_string);
			}
			DataReturn.append(" ");
		}
	}
	else {
		system("cls");
		cerr << "Impossible d'ouvrir le fichier" << "\n";
		system("pause");
	}
	return DataReturn;
}
