#include <iostream>
#include <fstream>
#include <string>
#include "Cesar.h"
#include "XOR.h"
#include "gestionFile.h"

using namespace std;
short Choice;
string message;

int main(){
	
	while (true) {
		cout << "Envoyer un messsage ou lire un message ?\n 1-Envoyer\n 2-Recevoir\n**> ";
		cin >> Choice;
		switch (Choice){
		case 1:
			system("cls");
			cout << "Entrez votre message a envoyer sans espace ou utilier des '_' \n**> ";
			cin >> message;
			Cesar* Mes;
			gestionFile* File;
			Mes = new Cesar();
			File = new gestionFile();
			File->openFileAndSave(Mes->Crypt_message(message));
			break;
		case 2:
			system("cls");

			break;
		default:
			cout << "Entrez un choix valide, 1 ou 2.\n";
			break;
		}
	}
	// Ecriture dans un fichier
	/*
		string const flux("C:/Users/maxcu/Documents/Code/encryptagee/test.txt");
		ofstream monFlux(flux.c_str());
		monFlux << "test ecriture dans un ficher mdr lol ptdr";
	*/
}